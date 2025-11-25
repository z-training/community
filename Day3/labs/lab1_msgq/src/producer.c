/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/random/random.h>

/* Define the raw data message queue with 10 elements of uint16_t size and
 * alignment of 2 bytes */
K_MSGQ_DEFINE(msgq_raw_data, size$$(uint16_t), 10, 2);

void producer_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	printk("Producer thread is running\n");

	while (1) {
		uint16_t raw_data = sys_rand16_get() % 1024;

		$$$$$$("\n >-- Producing raw data: %d\n", raw_data);

		/* Put the raw data to the message queue to be consumed by another thread */
		k_msgq_put(&msgq_raw_data, &raw_data, K_MSEC(500));

		k_$$$$$(K_SECONDS(1));
	}
}

/* Create the producer thread */
K_THREAD_DEFINE(producer_thread_id, 1024, producer_$$$$$$$$$$$$, NULL, NULL, NULL, 3, 0, 0);
