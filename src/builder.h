#ifndef JSON_BUILDER_H
#define JSON_BUILDER_H

/**
 * Create a JSON string instance.
 *
 * @param const char* string
 *   The object string value.
 *
 * @return struct json*
 *   Returns the JSON string instance; otherwise, NULL.
 */
struct json* json_string(const char* string);

/**
 * Create a JSON number instance.
 *
 * @param const double number
 *   The object number value.
 *
 * @return struct json*
 *   Returns the JSON number instance; otherwise, NULL.
 */
struct json* json_number(const double number);

/**
 * Create a JSON boolean instance.
 *
 * @param const int bool_value
 *   The boolean value as int.
 *
 * @return struct json*
 *   Returns the JSON boolean instance; otherwise, NULL.
 */
struct json* json_bool(const int bool_value);

/**
 * Create a JSON null instance.
 *
 * @return struct json*
 *   Returns the JSON null instance; otherwise, NULL.
 */
struct json* json_null();

/**
 * Create a JSON object instance.
 *
 * @param const char* key
 *   The object key.
 * @param void* value
 *   The object key.
 *
 * @return struct json*
 *   Returns the JSON object instance; otherwise, NULL.
 */
struct json* json_object(const char* key, void* value);

/**
 * Create a JSON string object instance.
 *
 * @param const char* key
 *   The object key.
 * @param const char* string
 *   The object string value.
 *
 * @return struct json*
 *   Returns the JSON object instance; otherwise, NULL.
 */
struct json* json_object_string(const char* key, const char* string);

/**
 * Create a JSON number object instance.
 *
 * @param const char* key
 *   The object key.
 * @param const double number
 *   The object number value.
 *
 * @return struct json*
 *   Returns the JSON object instance; otherwise, NULL.
 */
struct json* json_object_number(const char* key, const double number);

/**
 * Create a JSON array instance.
 *
 * @return struct json*
 *   Returns the JSON array instance; otherwise, NULL.
 */
struct json* json_array();

/**
 * Add the the given child JSON element onto the container JSON.
 *
 * @param struct json* container
 *   The container JSON intance.
 * @param struct json* child
 *   The child JSON intance.
 *
 * @return struct json*
 *   Returns the JSON object instance; otherwise, NULL.
 */
void json_push(struct json* container, struct json* child);

#endif
