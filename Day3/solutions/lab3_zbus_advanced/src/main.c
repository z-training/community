/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "producer.h"

#include <zephyr/kernel.h>
#include <zephyr/zbus/zbus.h>

/* Declare an external channel to use that in this file */
ZBUS_CHAN_DECLARE(chan_raw_data, chan_data);
ZBUS_OBS_DECLARE(lis_filter, sub_consumer, msub_consumer);

static void enable_filter()
{

	printk("\n+ Enabling filter ========\n");
	producer_stop();
	zbus_chan_add_obs(&chan_raw_data, &lis_filter, K_FOREVER);
	zbus_chan_rm_obs(&chan_raw_data, &sub_consumer, K_FOREVER);
	zbus_chan_rm_obs(&chan_raw_data, &msub_consumer, K_FOREVER);
	zbus_chan_add_obs(&chan_data, &sub_consumer, K_FOREVER);
	zbus_chan_add_obs(&chan_data, &msub_consumer, K_FOREVER);
	producer_start();
}

static void disable_filter()
{
	printk("\n+ Disabling filter ========\n");
	producer_stop();
	zbus_chan_rm_obs(&chan_raw_data, &lis_filter, K_FOREVER);
	zbus_chan_add_obs(&chan_raw_data, &sub_consumer, K_FOREVER);
	zbus_chan_add_obs(&chan_raw_data, &msub_consumer, K_FOREVER);
	zbus_chan_rm_obs(&chan_data, &sub_consumer, K_FOREVER);
	zbus_chan_rm_obs(&chan_data, &msub_consumer, K_FOREVER);
	producer_start();
}

int main()
{
	k_sleep(K_SECONDS(2));
	while (true) {
		enable_filter();

		k_sleep(K_SECONDS(5));

		disable_filter();

		k_sleep(K_SECONDS(5));
	}
	return 0;
}
