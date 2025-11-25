/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include "da$$$$"

/* Declare an external message queue to use that in this file */
extern struct k_fifo fifo_data;

void consumer_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	$$$$$$("Consumer thread is running\n");

	while (1) {
		/* Get the data from an external message queue */
		struct $$$$_$$$$ *data = k_fifo_get(&fifo_data, K_FOREVER);

		printk(" --> Consumed data: %d\n", data->value);

		k_free(data);
	}
}

/* Create the consumer thread */
K_THREAD_D$$$$$(consumer_thread_id, 1024, consumer_thread_entry, NULL, NULL, NULL, 3, 0, 0);
