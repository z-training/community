Lab 3: Custom Zephyr Shell Commands — Starter
=============================================

Overview
********

In this lab, you will build a simple application that introduces the Zephyr
shell subsystem. You'll create your own shell command group named **hakuna**
with a subcommand **matata**, allowing interactive runtime execution through
UART.

Learning Objectives
*******************

By completing this lab, you will:

- Configure the shell through Kconfig (`prj.conf`)
- Implement shell command handlers in C
- Create subcommand sets for grouped functionality

What You'll Implement
*********************

The starter project contains a basic structure. You will complete:

**main.c**
- Implement `cmd_hakuna()` and `cmd_matata()`
- Create a subcommand set with `SHELL_STATIC_SUBCMD_SET_CREATE`
- Register commands using `SHELL_CMD_REGISTER`

**prj.conf**
- Enable shell and UART backend


Testing the Commands
********************

Run the main command:

.. code-block:: console

   uart:~$ hakuna
   Hakuna means no !!! No what ?

Run the subcommand:

.. code-block:: console

   uart:~$ hakuna matata
   Hakuna Matata! It means no worries!

Check available commands:

.. code-block:: console

   uart:~$ help

Expected Output
***************

.. code-block:: console

   uart:~$ hakuna
   Hakuna means no !!! No what ?
   uart:~$ hakuna matata
   Hakuna Matata! It means no worries!
   uart:~$ help
