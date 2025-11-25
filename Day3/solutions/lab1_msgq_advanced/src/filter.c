/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

/* Declare an external message queue to use that in this file */
extern struct k_msgq msgq_raw_data;

/* Define the raw data message queue with 5 elements of uint16_t size and
 * alignment of 2 bytes */
K_MSGQ_DEFINE(msgq_data, sizeof(uint16_t), 5, 2);
K_MSGQ_DEFINE(msgq_data2, sizeof(uint16_t), 5, 2);

void filter_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	uint16_t data;

	printk("Filter thread is running\n");

	while (1) {

		/* Get the raw data from an external message queue */
		k_msgq_get(&msgq_raw_data, &data, K_FOREVER);

		printk(" -O- Filtering raw data: %d\n", data);

		/* Filter messages bigger than 512 */
		if (data > 512) {
			printk(" -x- Data %d is invalid\n", data);
		} else {
			/* Put the message in another message queue to be consumed by another thread
			 */
			k_msgq_put(&msgq_data, &data, K_FOREVER);
			k_msgq_put(&msgq_data2, &data, K_FOREVER);
		}
	}
}

/* Create the filter thread */
K_THREAD_DEFINE(filter_thread_id, 1024, filter_thread_entry, NULL, NULL, NULL, 3, 0, 0);
