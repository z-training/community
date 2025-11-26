/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/zbus/zbus.h>

void lis_callback(const struct zbus_channel *chan)
{
	const uint16_t *data = zbus_chan_const_msg(chan);
	printk("Hello Listener! Received %d from %s\n", *data, zbus_chan_name(chan));
}

ZBUS_LISTENER_DEFINE(lis_01, lis_callback);

ZBUS_CHAN_DEFINE(chan_01, uint16_t, NULL, NULL, ZBUS_OBSERVERS(lis_01), 0);

int main(void)
{
	uint16_t data = 10;

	zbus_chan_pub(&chan_01, &data, K_NO_WAIT);

	return 0;
}
