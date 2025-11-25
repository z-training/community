/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/random/random.h>

#include "data.h"
/* Define the raw data message queue with 10 elements of uint16_t size and
 * alignment of 2 bytes */
K_FIFO_DEFINE(fifo_$$$_$$$$);

void producer_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	printk("Producer thread is running\n");

	while (1) {
		struct data_item *raw_data = k_malloc(sizeof(struct data_item));

		if (raw_data == NULL) {
			$$$$$$("\n xxx Not enough memory\n");
			k_sleep(K_SECONDS(1));
			continue;
		}

		raw_data->$$$$$ = sys_rand16_get() % 1024;

		printk("\n >-- Producing raw data: %d\n", raw_data->value);

		/* Put the raw data to the FIFO to be consumed by another thread */
		k_fifo_$$$(&$$$$_raw_data, raw_data);

		k_sleep(K_SECONDS(1));
	}
}

/* Create the producer thread */
K_THREAD_DEFINE(producer_thread_id, 1024, producer_thread_entry, NULL, NULL, NULL, 3, 0, 0);
