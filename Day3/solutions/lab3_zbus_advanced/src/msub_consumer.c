/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/zbus/zbus.h>
#include <zephyr/zbus/zbus.h>

ZBUS_MSG_SUBSCRIBER_DEFINE(msub_consumer);

void msub_consumer_thread_entry(void *arg1, void *arg2, void *arg3)
{
	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	uint16_t data;
	const struct zbus_channel *chan;

	printk("MSG Subscriber consumer thread is running\n");

	while (1) {
		/* Wait for a notification for msub_consumer message subscriber */
		zbus_sub_wait_msg(&msub_consumer, &chan, &data, K_FOREVER);

		printk(" --> MSub consumed data: %d\n", data);
	}
}

/* Create the consumer thread */
K_THREAD_DEFINE(consumer_thread_id, 1024, msub_consumer_thread_entry, NULL, NULL, NULL, 3, 0, 0);
