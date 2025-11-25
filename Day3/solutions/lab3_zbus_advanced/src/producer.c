/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/zbus/zbus.h>
#include <zephyr/random/random.h>

/* Define the raw data channel with of uint16_t type */
ZBUS_CHAN_DEFINE(chan_raw_data, uint16_t, NULL, NULL, ZBUS_OBSERVERS_EMPTY, 0);

void timer_producer_handler(struct k_timer *timer_id)
{
	ARG_UNUSED(timer_id);

	uint16_t raw_data = sys_rand16_get() % 1024;

	printk("\n >-- Producing raw data: %d\n", raw_data);

	/* Publish the raw data message to the raw channel to be consumed by another thread */
	zbus_chan_pub(&chan_raw_data, &raw_data, K_MSEC(500));
}

K_TIMER_DEFINE(timer_producer, timer_producer_handler, NULL);

void producer_start()
{
	k_timer_start(&timer_producer, K_SECONDS(1), K_SECONDS(1));
}

void producer_stop()
{
	k_timer_stop(&timer_producer);
}
