/**
 * \file error.c
 * \brief Main definitions for c_traceback library
 *
 * \author Ching-Yin Ng
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "c_traceback.h"
#include "internal/common.h"
#include "internal/utils.h"

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

void ctb_print_inline_error(
    const char *restrict file,
    const int line,
    const char *restrict func,
    const int error_code,
    const char *restrict msg
)
{
    FILE *stream = stderr;
    const bool use_color = should_use_color(stream);

    if (use_color)
    {
        // clang-format off
        fprintf(
            stream,
            "%s%s:%s File %s\"%s\"%s, line %s%d%s in %s%s%s:\n    %s%s%s\n",
            CTB_ERROR_BOLD_COLOR, error_code_to_string(error_code), CTB_RESET_COLOR,
            CTB_TRACEBACK_FILE_COLOR, file, CTB_RESET_COLOR,
            CTB_TRACEBACK_LINE_COLOR, line, CTB_RESET_COLOR,
            CTB_TRACEBACK_FUNC_COLOR, func, CTB_RESET_COLOR,
            CTB_MESSAGE_COLOR, msg, CTB_RESET_COLOR
        );
        fflush(stream);
        // clang-format on
    }
    else
    {
        fprintf(
            stream,
            "%s: File \"%s\", line %d in %s:\n    %s\n",
            error_code_to_string(error_code),
            file,
            line,
            func,
            msg
        );
        fflush(stream);
    }
}

void ctb_print_inline_warning(
    const char *restrict file,
    const int line,
    const char *restrict func,
    const int error_code,
    const char *restrict msg
)
{
    FILE *stream = stderr;
    const bool use_color = should_use_color(stream);

    if (use_color)
    {
        // clang-format off
        fprintf(
            stream,
            "%s%s:%s File %s\"%s\"%s, line %s%d%s in %s%s%s:\n    %s%s%s\n",
            CTB_WARNING_BOLD_COLOR, error_code_to_string(error_code), CTB_RESET_COLOR,
            CTB_TRACEBACK_FILE_COLOR, file, CTB_RESET_COLOR,
            CTB_TRACEBACK_LINE_COLOR, line, CTB_RESET_COLOR,
            CTB_TRACEBACK_FUNC_COLOR, func, CTB_RESET_COLOR,
            CTB_MESSAGE_COLOR, msg, CTB_RESET_COLOR
        );
        fflush(stream);
        // clang-format on
    }
    else
    {
        fprintf(
            stream,
            "%s: File \"%s\", line %d in %s:\n    %s\n",
            error_code_to_string(error_code),
            file,
            line,
            func,
            msg
        );
        fflush(stream);
    }
}

void ctb_print_inline_message(
    const char *restrict file,
    const int line,
    const char *restrict func,
    const char *restrict msg
)
{
    FILE *stream = stdout;
    const bool use_color = should_use_color(stream);

    if (use_color)
    {
        // clang-format off
        fprintf(
            stream,
            "%sMessage:%s File %s\"%s\"%s, line %s%d%s in %s%s%s:\n    %s%s%s\n",
            CTB_MESSAGE_BOLD_COLOR, CTB_RESET_COLOR,
            CTB_TRACEBACK_FILE_COLOR, file, CTB_RESET_COLOR,
            CTB_TRACEBACK_LINE_COLOR, line, CTB_RESET_COLOR,
            CTB_TRACEBACK_FUNC_COLOR, func, CTB_RESET_COLOR,
            CTB_MESSAGE_COLOR, msg, CTB_RESET_COLOR
        );
        fflush(stream);
        // clang-format on
    }
    else
    {
        fprintf(
            stream,
            "Message: File \"%s\", line %d in %s:\n    %s\n",
            file,
            line,
            func,
            msg
        );
        fflush(stream);
    }
}