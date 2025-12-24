/**
 * \file utils.h
 * \brief Utility functions for c_traceback library.
 *
 * \author Ching-Yin Ng
 */

/**
 * \brief Convert error code to its corresponding string representation.
 *
 * \param[in] code The error code to convert.
 * \return A constant character pointer to the string representation of the error code.
 */
const char *error_code_to_string(int code);