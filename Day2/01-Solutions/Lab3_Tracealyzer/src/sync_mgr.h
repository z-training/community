/*
 * Copyright (c) 2024 Beningo Embedded Group
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file sync_mgr.h
 * @brief Synchronization Manager Module (Starter)
 */

#ifndef SYNC_MGR_H
#define SYNC_MGR_H

#include <zephyr/kernel.h>

/**
 * @brief Initialize the synchronization manager
 */
int sync_mgr_init(void);

/**
 * @brief Signal the event semaphore
 */
void sync_mgr_signal_event(void);

/**
 * @brief Wait for the event semaphore
 */
int sync_mgr_wait_event(k_timeout_t timeout);

#endif /* SYNC_MGR_H */
