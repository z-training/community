/*
 * Copyright (c) 2025 Ac6
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/shell/shell.h>

/* Runs when user types: hakuna */
static int cmd_hakuna(const struct shell *shell, size_t argc, char **argv)
{
    shell_print(shell, "Hakuna means no !!! No what ?");
    return 0;
}

/* Runs when user types: hakuna matata */
static int cmd_matata(const struct shell *shell, size_t argc, char **argv)
{
    shell_print(shell, "Hakuna Matata! It means no worries!");
    return 0;
}

/* Subcommands available under "hakuna" */
SHELL_STATIC_SUBCMD_SET_CREATE(sub_hakuna,
    SHELL_CMD(matata, NULL, "Print Hakuna Matata message", cmd_matata),
    SHELL_SUBCMD_SET_END
);

/* Register main command */
SHELL_CMD_REGISTER(hakuna, &sub_hakuna,
                   "Hakuna command root", cmd_hakuna);

