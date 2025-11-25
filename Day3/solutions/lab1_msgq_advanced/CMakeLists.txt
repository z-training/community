# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(msgq_adv)

target_sources(app PRIVATE src/producer.c src/filter.c src/consumer.c)
