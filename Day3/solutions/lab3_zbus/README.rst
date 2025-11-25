Lab 3: Data Passing — ZBus
==========================

Overview
********

In this lab, you will build a simple application that introduces the Zephyr
zbus. You will create a data passing flow between threads using zbus.

Learning Objectives
*******************

By completing this lab, you will:

- Use zbus
- Generate random numbers in test environment
- Implement a data passing flow in C

**prj.conf**
- Set heap CONFIG_HEAP_MEM_POOL_SIZE to 1024
- Enable CONFIG_ZBUS
- Enable CONFIG_ZBUS_MSG_SUBSCRIBER

Exercise 
********

Replace the $$$ to what makes sense based on the comments. 

Results should be like
**********************

Console output:

    *** Booting Zephyr OS build v4.2.1 ***
    Timer producer is starting
    MSG Subscriber consumer thread is running
    Subscriber consumer thread is running

    >-- Producing raw data: 343
    -O- Filtering raw data: 343
    --> MSub consumed data: 343
    --> Sub consumed data: 343

    >-- Producing raw data: 789
    -O- Filtering raw data: 789
    -x- Data 789 is invalid

    >-- Producing raw data: 552
    -O- Filtering raw data: 552
    -x- Data 552 is invalid

    >-- Producing raw data: 668
    -O- Filtering raw data: 668
    -x- Data 668 is invalid

    >-- Producing raw data: 371
    -O- Filtering raw data: 371
    --> MSub consumed data: 371
    --> Sub consumed data: 371

    ...<continues>

