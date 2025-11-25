Lab 1: Data Passing — Message queue
===================================

Overview
********

In this lab, you will build a simple application that introduces the Zephyr
message queue. You will create a data passing flow between threads using a
message queue.

Learning Objectives
*******************

By completing this lab, you will:

- Setup a message queue in Zephyr
- Generate random numbers in test environment
- Implement a data passing flow in C

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

    >-- Producing raw data: 56
    -O- Filtering raw data: 56
    --> Consumed data: 56

    >-- Producing raw data: 332
    -O- Filtering raw data: 332
    --> Consumed data: 332

    >-- Producing raw data: 954
    -O- Filtering raw data: 954
    -x- Data 954 is invalid

    >-- Producing raw data: 155
    -O- Filtering raw data: 155
    --> Consumed data: 155

    >-- Producing raw data: 527
    -O- Filtering raw data: 527
    -x- Data 527 is invalid

    ...<continues>
