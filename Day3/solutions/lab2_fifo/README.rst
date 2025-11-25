Lab 2: Data Passing — FIFO
==========================

Overview
********

In this lab, you will build a simple application that introduces the Zephyr
FIFO. You will create a data passing flow between threads using a FIFO.

Learning Objectives
*******************

By completing this lab, you will:

- Setup a FIFO in Zephyr
- Generate random numbers in test environment
- Dynamic allocation  
- Implement a data passing flow in C

**prj.conf**
- Set heap CONFIG_HEAP_MEM_POOL_SIZE to 1024

Exercise 
********

Replace the $$$ to what makes sense based on the comments. 

Results should be like
**********************

Console output:

    *** Booting Zephyr OS build v4.2.1 ***
    Consumer thread is running
    Filter thread is running
    Producer thread is running

    >-- Producing raw data: 146
    -O- Filtering raw data: 146
    --> Consumed data: 146

    >-- Producing raw data: 203
    -O- Filtering raw data: 203
    --> Consumed data: 203

    >-- Producing raw data: 864
    -O- Filtering raw data: 864
    -x- Data 864 is invalid

    >-- Producing raw data: 189
    -O- Filtering raw data: 189
    --> Consumed data: 189

    >-- Producing raw data: 473
    -O- Filtering raw data: 473
    --> Consumed data: 473

    ...<continues>

