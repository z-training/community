# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(msgq)

target_sources(app PRIVATE
    #src/hello_listener.c
    src/hello_subscriber.c
    #src/hello_msg_subscriber.c
)
