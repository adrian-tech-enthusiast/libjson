#ifndef JSON_PRINT_H
#define JSON_PRINT_H

#include "json.h"

/**
 * Prints a JSON string.
 *
 * @param const char* json_string
 *   The json string to print.
 */
void json_string_print(const char* json_string);

/**
 * Prints a JSON object.
 *
 * @param struct json* object
 *   The JSON object to print.
 */
void json_object_print(struct json* object);

#endif
