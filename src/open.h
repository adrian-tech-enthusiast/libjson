#ifndef JSON_OPEN_H
#define JSON_OPEN_H

#include "json.h"

/**
 * Reads the given JSON file path and decodes its contents.
 *
 * @param const char* filepath
 *   The filepath with the model content.
 *
 * @return struct json*
 *   The pointer to the JSON object, otherwise NULL.
 */
struct json* json_open(const char* filepath);

#endif
