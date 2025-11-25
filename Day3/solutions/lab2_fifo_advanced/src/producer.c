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
K_FIFO_DEFINE(fifo_data_used);
K_FIFO_DEFINE(fifo_data_free);

static struct data_item data[4];

void producer_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	int i;

	for (i = 0; i < ARRAY_SIZE(data); i++) {
		k_fifo_put(&fifo_data_free, &data[i]);
	}

	printk("Producer thread is running\n");

	while (1) {
		struct data_item *raw_data = k_fifo_get(&fifo_data_free, K_FOREVER);

		raw_data->value = sys_rand16_get() % 1024;

		printk("\n >-- Producing raw data: %d\n", raw_data->value);

		/* Put the raw data to the message queue to be consumed by another thread */
		k_fifo_put(&fifo_data_used, raw_data);

		k_sleep(K_SECONDS(1));
	}
}

/* Create the producer thread */
K_THREAD_DEFINE(producer_thread_id, 1024, producer_thread_entry, NULL, NULL, NULL, 4, 0, 0);
