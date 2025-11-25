/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/zbus/zbus.h>
#include <zephyr/zbus/zbus.h>

/* Declare an external channel to use that in this file */
ZBUS_CHAN_DECLARE(chan_data);

ZBUS_MSG_SUBSCRIBER_DEFINE(msub_$$$$$$$$);

/* Add msub_consumer to the channel data as an observer */
ZBUS_$$$$_ADD_OBS(chan_data, msub_consumer, 3);

void msub_consumer_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	uint16_t data;
	const struct zbus_ch$$$$$ *chan;

	printk("MSG Subscriber consumer thread is running\n");

	while (1) {
		/* Wait for a notification for msub_consumer message subscriber */
		$$$$_sub_wait_msg(&msub_consumer, &chan, &data, K_FOREVER);

		printk(" --> MSub consumed data: %d\n", data);
	}
}

/* Create the consumer thread */
K_THREAD_DEFINE(consumer_thread_id, 1024, msub_consumer_thread_entry, NULL, NULL, NULL, 3, 0, 0);
