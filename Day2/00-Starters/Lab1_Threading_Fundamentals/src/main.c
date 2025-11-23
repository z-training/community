/*
 * Copyright (c) 2016 Intel Corporation
 * Copyright (c) 2024 Beningo Embedded Group
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file main.c
 * @brief Lab 1 - Zephyr Threading Fundamentals (Starter)
 *
 * This starter project provides a basic blinky application.
 * You will enhance it to explore Zephyr's threading model and initialization.
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* LED blink timing */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias */
#define LED0_NODE DT_ALIAS(led0)

/* GPIO device specification from devicetree */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

/**
 * @brief Main thread entry point
 *
 * TODO: Add functionality to explore the main thread and idle thread
 */
/**
 * @brief Print system initialization information
 */
static void print_system_info(void)
{
    printk("\n");
    printk("========================================\n");
    printk("  Lab 1: Threading Fundamentals\n");
    printk("========================================\n");
    printk("System initialized successfully\n");
    printk("Current thread: %s\n", k_thread_name_get(k_current_get()));
    printk("Main thread priority: %d\n", k_thread_priority_get(k_current_get()));
    printk("========================================\n");
    printk("\n");
}

/**
 * @brief Print idle thread information
 */
static void print_idle_thread_info(void)
{
    printk("\n");
    printk("--- Idle Thread Information ---\n");
    printk("The idle thread runs when no other threads are ready.\n");
    printk("It has the lowest priority in the system.\n");
    printk("During idle, the CPU can enter low-power modes.\n");
    printk("The Idle thread can’t be directly modified by the developer.\n");
    printk("-------------------------------\n");
    printk("\n");
}

int main(void)
{
    int ret;
    bool led_state = true;
    uint32_t blink_count = 0;  

    print_system_info();

    /* Check if LED device is ready */
    if (!gpio_is_ready_dt(&led)) {
        printk("Error: LED device %s is not ready\n", led.port->name);
        return -1;
    }

    /* Configure LED pin as output */
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error: Failed to configure LED pin\n");
        return ret;
    }

    printk("LED blinky application started\n");

    print_idle_thread_info();

    /* Main application loop */
    while (1) {
        /* Toggle the LED */
        ret = gpio_pin_toggle_dt(&led);
        if (ret < 0) {
            printk("Error: Failed to toggle LED\n");
            return ret;
        }

        led_state = !led_state;
          blink_count++;

        /* Print status every blink */
        printk("[Main Thread] Blink #%u - LED state: %s\n",
            blink_count,
            led_state ? "ON" : "OFF");

        /* Provide additional information periodically */
        if (blink_count % 5 == 0) {
            printk("  [Info] Main thread has executed %u blinks\n", blink_count);
            printk("  [Info] During k_msleep(), other threads can execute\n");
        }

        /*
         * Sleep for the specified duration
         *
         * k_msleep() suspends the current thread for the specified time.
         * This allows the scheduler to run other threads or the idle thread.
         * The thread will be woken up when the timeout expires.
         */
        k_msleep(SLEEP_TIME_MS);
    }

    return 0;
}
