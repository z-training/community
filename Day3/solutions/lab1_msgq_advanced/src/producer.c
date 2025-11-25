/*
 * Copyright (c) 2025 Citrinio
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/random/random.h>

/* Define the raw data message queue with 10 elements of uint16_t size and
 * alignment of 2 bytes */

K_MSGQ_DEFINE(msgq_raw_data, sizeof(uint16_t), 10, 2);

void timer_producer_handler(struct k_timer *timer_id)
{
	ARG_UNUSED(timer_id);

	uint16_t raw_data = sys_rand16_get() % 1024;

	printk("\n >-- Producing raw data: %d\n", raw_data);

	/* Put the raw data to the message queue to be consumed by another thread */
	k_msgq_put(&msgq_raw_data, &raw_data, K_MSEC(500));
}

K_TIMER_DEFINE(timer_producer, timer_producer_handler, NULL);

int timer_producer_start(void)
{
	printk("Timer Producer is starting\n");

	k_timer_start(&timer_producer, K_SECONDS(1), K_SECONDS(1));

	return 0;
}

SYS_INIT(timer_producer_start, APPLICATION, 99);
