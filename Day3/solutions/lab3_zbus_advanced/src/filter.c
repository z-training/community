/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/zbus/zbus.h>

/* Define the raw data channel of uint16_t type */
ZBUS_CHAN_DEFINE(chan_data, uint16_t, NULL, NULL, ZBUS_OBSERVERS_EMPTY, 0);

void lis_filter_callback(const struct zbus_channel *chan)
{
	const uint16_t *data = zbus_chan_const_msg(chan);

	printk(" -O- Filtering raw data: %d\n", *data);

	/* Filter messages bigger than 512 */
	if (*data > 512) {
		printk(" -x- Data %d is invalid\n", *data);
	} else {
		/* Publish the message in another channel to be consumed by another thread
		 */
		zbus_chan_pub(&chan_data, data, K_MSEC(500));
	}
}

/* Define the filter listener */
ZBUS_LISTENER_DEFINE(lis_filter, lis_filter_callback);
