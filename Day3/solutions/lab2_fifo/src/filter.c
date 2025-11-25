/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include "data.h"
/* Declare an external message queue to use that in this file */
extern struct k_fifo fifo_raw_data;

K_FIFO_DEFINE(fifo_data);

void filter_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	printk("Filter thread is running\n");

	while (1) {

		/* Get the raw data from an external message queue */
		struct data_item *raw_data = k_fifo_get(&fifo_raw_data, K_FOREVER);

		printk(" -O- Filtering raw data: %d\n", raw_data->value);

		/* Filter messages bigger than 512 */
		if (raw_data->value > 512) {
			printk(" -x- Data %d is invalid\n", raw_data->value);
			k_free(raw_data);
			continue;
		}

		/* Put the message in another message queue to be consumed by another thread
		 */

		k_fifo_put(&fifo_data, raw_data);
	}
}

/* Create the filter thread */
K_THREAD_DEFINE(filter_thread_id, 1024, filter_thread_entry, NULL, NULL, NULL, 3, 0, 0);
