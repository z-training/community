Lab 1: Zephyr Threading Fundamentals - Starter
===============================================

Overview
********

This starter project provides a basic LED blinky application that you will
enhance to explore Zephyr's threading model and initialization sequence.

Learning Objectives
*******************

By completing this lab, you will:

- Understand the Zephyr boot sequence and system initialization
- Learn about the main thread and its default priority
- Discover the idle thread and when it executes
- Practice using Zephyr kernel APIs to query thread information

Building and Running
********************

Build and flash this starter project as follows:

.. code-block:: console

   cd Labs/Lab1_Threading_Fundamentals/00-Starter
   west build -b stm32f746g_disco
   west flash

What You'll Add
***************

During the lab, you will enhance this basic blinky to:

1. Print system initialization information
2. Display the main thread's name and priority
3. Explain the idle thread's purpose
4. Add detailed status messages during LED blinking
5. Provide insights into thread scheduling behavior

TODOs in the Code
*****************

Look for ``TODO`` comments in main.c for guidance on what to add.
Refer to the lab manual for step-by-step instructions.

Useful Zephyr APIs
******************

You'll use these kernel APIs:

- ``k_current_get()`` - Get pointer to the current thread
- ``k_thread_name_get(thread)`` - Get the name of a thread
- ``k_thread_priority_get(thread)`` - Get the priority of a thread
- ``k_msleep(ms)`` - Sleep for specified milliseconds

Next Steps
**********

Follow the lab manual instructions to complete this lab. Compare your
implementation with the solution in the 01-Solution directory.
