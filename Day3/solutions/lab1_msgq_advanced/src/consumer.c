/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>

/* Declare an external message queue to use that in this file */
extern struct k_msgq msgq_data;
extern struct k_msgq msgq_data2;

void consumer_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg3);

	uint16_t data;
	int consumer_id = *((int *)arg1);
	struct k_msgq *msgq = arg2;

	printk("Consumer %d thread is running\n", consumer_id);

	while (1) {
		/* Get the data from an external message queue */
		k_msgq_get(msgq, &data, K_FOREVER);

		printk(" --> C%d consumed data: %d\n", consumer_id, data);
	}
}

/* Create the consumer thread */
K_THREAD_DEFINE(consumer1_thread_id, 1024, consumer_thread_entry, &(int){1}, &msgq_data, NULL, 3, 0,
		0);
K_THREAD_DEFINE(consumer2_thread_id, 1024, consumer_thread_entry, &(int){2}, &msgq_data2, NULL, 3,
		0, 0);
