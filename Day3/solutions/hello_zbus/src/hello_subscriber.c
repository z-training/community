/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <stdint.h>
#include <zephyr/kernel.h>
#include <zephyr/zbus/zbus.h>

ZBUS_SUBSCRIBER_DEFINE(msub_01, 4);

ZBUS_CHAN_DEFINE(chan_01, uint16_t, NULL, NULL, ZBUS_OBSERVERS(msub_01), 0);

int main(void)
{
	uint16_t data = 10;

	zbus_chan_pub(&chan_01, &data, K_NO_WAIT);

	return 0;
}

void zbus_subscriber_thread_main(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p1);
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);

	uint16_t data;
	const struct zbus_channel *chan;

	while (1) {
		zbus_sub_wait(&msub_01, &chan, K_FOREVER);

		zbus_chan_read(&chan_01, &data, K_NO_WAIT);

		printk("Hello Subscriber! Received %d from %s\n", data, zbus_chan_name(chan));
	}
}

K_THREAD_DEFINE(sub_thread, 1024, zbus_subscriber_thread_main, NULL, NULL, NULL, 4, 0, 0);
