/**
 * \file c_traceback.h
 * \brief Library header for c_traceback library
 *
 * \author Ching-Yin Ng
 */

#ifndef C_TRACEBACK_H
#define C_TRACEBACK_H

#include "c_traceback_colors.h"
#include "c_traceback_error_codes.h"

typedef struct CTB_Context CTB_Context;

// Maximum number of traceback frames
#define MAX_TRACEBACK_FRAMES 64

/**
 * \brief Wrapper for printing an inline error.
 *
 * \param[in] error_code Error code associated with the error.
 * \param[in] msg Error message.
 */
#define CTB_PRINT_INLINE_ERROR(error_code, msg)                                        \
    do                                                                                 \
    {                                                                                  \
        ctb_print_inline_error(__FILE__, __LINE__, __func__, error_code, msg);         \
    } while (0)

/**
 * \brief Wrapper for printing an inline warning.
 *
 * \param[in] error_code Error code associated with the warning.
 * \param[in] msg Warning message.
 */
#define CTB_PRINT_INLINE_WARNING(error_code, msg)                                      \
    do                                                                                 \
    {                                                                                  \
        ctb_print_inline_warning(__FILE__, __LINE__, __func__, error_code, msg);       \
    } while (0)

/**
 * \brief Wrapper for printing an inline message.
 *
 * \param[in] msg Warning message.
 */
#define CTB_PRINT_INLINE_MESSAGE(msg)                                                  \
    do                                                                                 \
    {                                                                                  \
        ctb_print_inline_message(__FILE__, __LINE__, __func__, msg);                   \
    } while (0)

CTB_Context *ctb_make_context(void);
void ctb_free_context(CTB_Context *restrict context);

/**
 * \brief Print inline error message to stderr.
 *
 * \param[in] file File where the error occurs.
 * \param[in] line Line number where the error occurs.
 * \param[in] func Function where the error occurs.
 * \param[in] error_code Error code associated with the error.
 * \param[in] msg Error message.
 */
void ctb_print_inline_error(
    const char *restrict file,
    const int line,
    const char *restrict func,
    const int error_code,
    const char *restrict msg
);

/**
 * \brief Print inline warning message to stderr.
 *
 * \param[in] file File where the warning occurs.
 * \param[in] line Line number where the warning occurs.
 * \param[in] func Function where the warning occurs.
 * \param[in] error_code Error code associated with the warning.
 * \param[in] msg Warning message.
 */
void ctb_print_inline_warning(
    const char *restrict file,
    const int line,
    const char *restrict func,
    const int error_code,
    const char *restrict msg
);

/**
 * \brief Print message to stdout.
 *
 * \param[in] file File where the message is sent.
 * \param[in] line Line number where the message is sent.
 * \param[in] func Function where the message is sent.
 * \param[in] msg Message.
 */
void ctb_print_inline_message(
    const char *restrict file,
    const int line,
    const char *restrict func,
    const char *restrict msg
);

#endif /* C_TRACEBACK_H */
