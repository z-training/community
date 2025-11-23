/*
 * Copyright (c) 2024 Beningo Embedded Group
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file periodic_thread.c
 * @brief Periodic Thread Implementation (Starter)
 */

#include "periodic_thread.h"
#include "sync_mgr.h"
#include <zephyr/kernel.h>

#define PERIODIC_THREAD_STACK_SIZE  1024
#define PERIODIC_THREAD_PRIORITY    7
#define PERIOD_MS                   2000

static K_THREAD_STACK_DEFINE(periodic_thread_stack, PERIODIC_THREAD_STACK_SIZE);
static struct k_thread periodic_thread_data;

static uint32_t execution_count = 0;

static void periodic_thread_entry(void *arg1, void *arg2, void *arg3)
{
    ARG_UNUSED(arg1);
    ARG_UNUSED(arg2);
    ARG_UNUSED(arg3);

    printk("[Periodic Thread] Started\n");

    while (1) {
        execution_count++;

        printk("[Periodic Thread] Execution #%u - Signaling event thread\n", execution_count);

        sync_mgr_signal_event();

        k_msleep(PERIOD_MS);
    }
}

int periodic_thread_init(void)
{
    k_tid_t tid;

    tid = k_thread_create(&periodic_thread_data,
                          periodic_thread_stack,
                          K_THREAD_STACK_SIZEOF(periodic_thread_stack),
                          periodic_thread_entry,
                          NULL, NULL, NULL,
                          PERIODIC_THREAD_PRIORITY,
                          0,
                          K_NO_WAIT);

    if (tid == NULL) {
        printk("[Periodic Thread] ERROR: Failed to create thread\n");
        return -1;
    }

    printk("[Periodic Thread] Initialized\n");
    return 0;
}
