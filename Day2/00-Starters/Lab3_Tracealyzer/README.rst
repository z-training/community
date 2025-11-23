Lab 2: Thread Synchronization - Starter
========================================

Overview
********

In this lab, you'll implement a multi-threaded application with semaphore-based
synchronization. You'll create two threads:

- **Periodic Thread**: Runs every 2 seconds, signals the event thread
- **Event Thread**: Blocks waiting for signals, toggles LED when signaled

This demonstrates key RTOS concepts:

- Creating custom threads with priorities
- Inter-thread synchronization using semaphores
- Periodic vs event-driven execution models
- Production code architecture (modular, no globals)

Learning Objectives
*******************

By completing this lab, you will:

- Create and configure threads with k_thread_create()
- Implement semaphore signaling between threads
- Understand thread priorities and preemption
- Design event-driven tasks that block efficiently
- Apply production code practices (encapsulation, modularity)

What You'll Implement
*********************

The starter project provides the skeleton. You'll complete:

**sync_mgr Module**
- Define semaphore using K_SEM_DEFINE
- Implement sync_mgr_signal_event() using k_sem_give()
- Implement sync_mgr_wait_event() using k_sem_take()

**periodic_thread Module**
- Define thread stack and control block
- Create thread with k_thread_create()
- Implement periodic signaling with k_msleep()

**event_thread Module**
- Define thread stack and control block
- Create higher-priority thread
- Implement event-driven blocking with K_FOREVER timeout
- Toggle LED on event reception

**main Module**
- Initialize all subsystems in proper order
- Handle initialization errors

Building and Running
********************

Build and flash:

.. code-block:: console

   cd Labs/Lab2_Synchronization/00-Starter
   west build -b stm32f746g_disco
   west flash

Look for TODO comments in the source files for guidance.

Expected Behavior (When Complete)
**********************************

Console output:

.. code-block:: console

   ========================================
     Lab 2: Thread Synchronization
   ========================================

   [Sync Manager] Initialized
   [Event Thread] Initialized
   [Event Thread] Started
   [Event Thread] Waiting for events...
   [Periodic Thread] Initialized
   [Periodic Thread] Started

   [Main] System operational

   [Periodic Thread] Execution #1 - Signaling event thread
   [Event Thread] Event #1 received - LED toggled
   ...

Hardware: LED toggles every 2 seconds

Next Steps
**********

Follow the lab manual for step-by-step instructions. Compare your
implementation with the solution in 01-Solution.
