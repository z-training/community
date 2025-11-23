/*
 * Copyright (c) 2024 Beningo Embedded Group
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file main.c
 * @brief Lab 2 - Thread Synchronization (Starter)
 */

#include <zephyr/kernel.h>
#include "sync_mgr.h"
#include "periodic_thread.h"
#include "event_thread.h"

int main(void)
{
    int ret;

    printk("\n");
    printk("========================================\n");
    printk("  Lab 2: Thread Synchronization\n");
    printk("========================================\n");
    printk("\n");

    ret = sync_mgr_init();
    if (ret < 0) {
        printk("[Main] ERROR: Sync manager init failed\n");
        return ret;
    }


    ret = event_thread_init();
    if (ret < 0) {
        printk("[Main] ERROR: Event thread init failed\n");
        return ret;
    }

    /* Small delay to let event thread initialize */
    k_msleep(100);

    ret = periodic_thread_init();
    if (ret < 0) {
        printk("[Main] ERROR: Periodic thread init failed\n");
        return ret;
    }

    printk("\n");
    printk("[Main] System operational\n");
    printk("\n");

    /* Main thread enters monitoring loop */
    while (1) {
        k_sleep(K_SECONDS(60));
        printk("[Main] System running...\n");
    }

    return 0;
}
