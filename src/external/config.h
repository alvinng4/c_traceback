/**
 * \file config.h
 * \brief Configuration header for c_traceback library
 *
 * \author Ching-Yin Ng
 */

#ifndef CTB_CONFIG_H
#define CTB_CONFIG_H

// Maximum number of call stack frames
#define CTB_MAX_CALL_STACK_DEPTH 32

// Maximum number of simultaneous errors
#define CTB_MAX_NUM_ERROR 8

// Maximum length of error message
#define CTB_MAX_ERROR_MESSAGE_LENGTH 256

#endif /* CTB_CONFIG_H */
