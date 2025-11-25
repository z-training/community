/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/zbus/zbus.h>

/* Declare an external message queue to use that in this file */
ZBUS_CHAN_DECLARE(chan_data);

ZBUS_SUBSCRIBER_DEFINE(sub_consumer, 4);

ZBUS_CHAN_ADD_OBS(chan_data, sub_consumer, 3);

void sub_consumer_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	uint16_t data;
	const struct zbus_channel *chan;

	printk("Subscriber consumer thread is running\n");

	while (1) {
		/* Wait for the notification on the subcriber consumer */
		zbus_sub_wait(&sub_consumer, &chan, K_FOREVER);

		/* Read the channel to access the message */
		zbus_chan_read(chan, &data, K_MSEC(500));

		printk(" --> Sub consumed data: %d\n", data);
	}
}

/* Create the consumer thread */
K_THREAD_DEFINE(sub_consumer_thread_id, 1024, sub_consumer_thread_entry, NULL, NULL, NULL, 3, 0, 0);
