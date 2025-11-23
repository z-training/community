/*
 * Copyright (c) 2024 Beningo Embedded Group
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file event_thread.c
 * @brief Event-Driven Thread Implementation (Starter)
 */

#include "event_thread.h"
#include "sync_mgr.h"
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define EVENT_THREAD_STACK_SIZE     1024
#define EVENT_THREAD_PRIORITY       6

#define LED0_NODE DT_ALIAS(led0)

static K_THREAD_STACK_DEFINE(event_thread_stack, EVENT_THREAD_STACK_SIZE);
static struct k_thread event_thread_data;

static uint32_t event_count = 0;
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

static int gpio_init(void)
{
    int ret;

    if (!gpio_is_ready_dt(&led)) {
        printk("[Event Thread] ERROR: LED device not ready\n");
        return -ENODEV;
    }

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
    if (ret < 0) {
        printk("[Event Thread] ERROR: Failed to configure LED\n");
        return ret;
    }

    return 0;
}

static void event_thread_entry(void *arg1, void *arg2, void *arg3)
{
    int ret;

    ARG_UNUSED(arg1);
    ARG_UNUSED(arg2);
    ARG_UNUSED(arg3);

    printk("[Event Thread] Started\n");

    ret = gpio_init();
    if (ret < 0) {
        printk("[Event Thread] GPIO init failed\n");
        return;
    }

    printk("[Event Thread] Waiting for events...\n");

    while (1) {
        ret = sync_mgr_wait_event(K_FOREVER);

        if (ret == 0) {
            event_count++;
            gpio_pin_toggle_dt(&led);
            printk("[Event Thread] Event #%u received - LED toggled\n",
                event_count);
        }
    }
}

int event_thread_init(void)
{
    k_tid_t tid;

    tid = k_thread_create(&event_thread_data,
                          event_thread_stack,
                          K_THREAD_STACK_SIZEOF(event_thread_stack),
                          event_thread_entry,
                          NULL, NULL, NULL,
                          EVENT_THREAD_PRIORITY,
                          0,
                          K_NO_WAIT);

    if (tid == NULL) {
        printk("[Event Thread] ERROR: Failed to create thread\n");
        return -1;
    }

    printk("[Event Thread] Initialized\n");
    return 0;
}
