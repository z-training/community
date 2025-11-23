# External LED Blink Example — Zephyr

This example demonstrates how to blink **four external LEDs** connected to a
Zephyr-supported board. The LED GPIOs are defined in the Devicetree using the
aliases:

- my_led0
- my_led1
- my_led2
- my_led3

The application retrieves these aliases, configures each pin as an output, and
blinks the LEDs sequentially.

---

## Requirements

- Zephyr RTOS installed
- Board with 4 external LEDs connected and defined in Devicetree
- Overlay providing my_led0 → my_led3 aliases

---

## Expected Behavior

- LEDs are configured as outputs at startup
- LEDs toggle **one after another**
- Each LED changes state every **500 ms**
- Sequence repeats forever

Visual LED blinking confirms success.

---

Happy blinking! ✨
