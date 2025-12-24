/**
 * \file error.c
 * \brief Main definitions for c_traceback library
 *
 * \author Ching-Yin Ng
 */

#include <stdio.h>
#include <stdlib.h>

#include "c_traceback.h"
#include "internal/common.h"
#include "internal/utils.h"

#define RESET "\033[0m"
#define BRIGHT_RED "\033[1;31m"
#define DIM_RED "\033[5;31m"
#define YELLOW_BOLD "\033[1;33m"
#define CYAN_REGULAR "\033[0;36m"
#define PURPLE_REGULAR "\033[0;35m"
#define PURPLE_BRIGHT "\033[0;95m"
#define PURPLE_BRIGHT_BOLD "\033[1;95m"

CTB_Context *ctb_make_context(void)
{
    CTB_Context *restrict context = malloc(sizeof(CTB_Context));
    if (context)
    {
        context->num_errors = 0;
    }
    return context;
}

void ctb_free_context(CTB_Context *restrict context)
{
    if (!context)
    {
        return;
    }
}

void ctb_print_warning(
    const char *restrict warning_file,
    const int warning_line,
    const char *restrict warning_func,
    const int error_code,
    const char *restrict warning_msg
)
{
    fprintf(
        stderr,
        "%s%s:%s In %s\"%s\"%s, line %s%d%s in %s%s%s:\n    %s%s%s\n",
        YELLOW_BOLD,
        error_code_to_string(error_code),
        RESET,
        CYAN_REGULAR,
        warning_file,
        RESET,
        CYAN_REGULAR,
        warning_line,
        RESET,
        CYAN_REGULAR,
        warning_func,
        RESET,
        PURPLE_REGULAR,
        warning_msg,
        RESET
    );
    fflush(stderr);
}