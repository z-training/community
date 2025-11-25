/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>

/* Declare an external message queue to use that in this file */
extern struct k_msgq msgq_$$$$;

void $$$$$$$$_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	uint16_t data;

	printk("Consumer thread is running\n");

	while (1) {
		/* Get the data from an external message queue. Waits forever */
		k_msgq_get(&msgq_data, &data, $_$$$$$$$);

		printk(" --> Consumed data: %d\n", data);
	}
}

/* Create the consumer thread */
K_THREAD_DEFINE(consumer_thread_id, 1024, consumer_thread_entry, NULL, NULL, NULL, 3, 0, 0);
