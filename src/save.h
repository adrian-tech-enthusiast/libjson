#ifndef JSON_SAVE_H
#define JSON_SAVE_H

#include "json.h"

/**
 * Saves the given JSON object to the given file path.
 *
 * @param struct json* json_object
 *   The JSON object to save.
 * @param const char* filepath
 *   The filepath with the JSON content.
 *
 * @return int
 *   Returns 1 when the the JSON file was saved, otherwise 0.
 */
int json_save(struct json* json_object, const char* filepath);

#endif
