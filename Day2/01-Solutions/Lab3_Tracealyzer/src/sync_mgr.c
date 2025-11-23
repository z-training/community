/*
 * Copyright (c) 2024 Beningo Embedded Group
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file sync_mgr.c
 * @brief Synchronization Manager Implementation (Starter)
 */

#include "sync_mgr.h"
#include <zephyr/kernel.h>

/* 
 * Initial count should be 0 (no events pending at startup)
 * Limit should be 1 (binary semaphore)
 */
static K_SEM_DEFINE(event_sem, 0, 1);

int sync_mgr_init(void)
{
    printk("[Sync Manager] Initialized\n");
    return 0;
}

void sync_mgr_signal_event(void)
{
    k_sem_give(&event_sem);
}

int sync_mgr_wait_event(k_timeout_t timeout)
{
    return k_sem_take(&event_sem, timeout);
}
