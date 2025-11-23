/*
 * Copyright (c) 2025 Ac6
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* Get LEDs from Devicetree */
static const struct gpio_dt_spec leds[] = {
    GPIO_DT_SPEC_GET(..., gpios),
    GPIO_DT_SPEC_GET(..., gpios),
    GPIO_DT_SPEC_GET(..., gpios),
    GPIO_DT_SPEC_GET(..., gpios),
};

int main(void)
{
    /* Configure all LEDs as outputs */
    for (int i = 0; i < ARRAY_SIZE(leds); i++) {
        if (!gpio_is_ready_dt(&leds[i])) {
            return 0;
        }
		/* Configure the gpio */
        ...(&leds[i], GPIO_OUTPUT_INACTIVE);
    }

    /* Blink forever */
    while (1) {
        for (int i = 0; i < ARRAY_SIZE(leds); i++) {
			/* Toggle the gpio */
            ...(&leds[i]);
			k_msleep(500);
        }
    }
}
