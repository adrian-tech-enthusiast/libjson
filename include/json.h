#ifndef JSON_H
#define JSON_H

/**
 * Supported JSON Data Types.
 *
 * In JSON, values must be one of the following data types:
 */
enum JSONDataType {
  JSON_string,
  JSON_number,
  JSON_object,
  JSON_array,
  JSON_boolean,
  JSON_null
};

/**
 * The data struct definition for an individual JSON object.
 */
struct json {

  /**
   * Pointer to the next JSON object in the chain.
   *
   * Allow you to walk array/object chains.
   *
   * @var struct json* next.
   */
  struct json *next;

  /**
   * Pointer to the prev JSON object in the chain.
   *
   * Allow you to walk array/object chains.
   *
   * @var struct json* prev.
   */
  struct json *prev;

  /**
   * The type of data that is stored in the current entry/node.
   *
   * @see enum JSONDataTypes.
   *
   * @var struct json* type.
   */
  enum JSONDataType type;

  /**
   * The key for the current entry/node.
   *
   * @var char* key.
   */
  char *key;

  /**
   * The value for the current entry/node.
   *
   * @var char* value.
   */
  void *value;
};

/*
 * Create a new JSON object instance.
 *
 * @param enum JSONDataType type
 *   The Supported JSON Data Type.
 * @param void* value
 *   The pointer value.
 *
 * @return struct json*
 *   The pointer to the json instance, otherwise NULL.
 */
struct json *json_create(enum JSONDataType type, void *value);

/**
 * Takes a JSON encoded string and converts it into a JSON object.
 *
 * @param const char* json
 *   The json string being decoded.
 *
 * @return struct json*
 *   The pointer to the JSON object, otherwise NULL.
 */
struct json *json_decode(const char *json_string);

/**
 * Returns a string containing the JSON representation of the supplied JSON object.
 *
 * @param struct json* object
 *   The JSON object being encoded.
 *
 * @return char*
 *   The string pointer containing the JSON representation, otherwise NULL.
 */
char *json_encode(struct json *object);

/**
 * Free the memory associted to a JSON object.
 *
 * @param struct json* object
 *   The JSON object to be cleaned.
 */
void json_destroy(struct json *object);

#endif /* JSON_H */

#ifndef JSON_ITERATOR_H
#define JSON_ITERATOR_H

/**
 * Find node in the given JSON object.
 *
 * @param struct json* object
 *   The JSON object to search.
 * @param const char* path
 *   The path to find the node.
 * @param const char delimiter
 *   The path delimiter.
 *
 * @return struct json*
 *   The pointer to the JSON node object, if found; otherwise NULL.
 */
struct json *json_find_node(struct json *object, const char *path, const char delimiter);

/**
 * Find node by index in the given JSON object.
 *
 * @param struct json* object
 *   The JSON object to search.
 * @param const int index
 *   The index to search.
 *
 * @return struct json*
 *   The pointer to the JSON node object, if found; otherwise NULL.
 */
struct json *json_find_node_by_index(struct json *object, const int index);

#endif /* JSON_ITERATOR_H */

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
struct json *json_string(const char *string);

/**
 * Create a JSON number instance.
 *
 * @param const double number
 *   The object number value.
 *
 * @return struct json*
 *   Returns the JSON number instance; otherwise, NULL.
 */
struct json *json_number(const double number);

/**
 * Converts a double number to a JSON string representation.
 *
 * This function takes a double precision number and converts it into
 * a JSON string representation. It first converts the number to a
 * string using the `ldtos` function, and then creates a JSON object
 * using this string. If the conversion or the JSON object creation
 * fails, it returns NULL.
 *
 * @param const double number
 *   The object number value.
 *
 * @return struct json*
 *   Returns the JSON number string instance; otherwise, NULL.
 */
struct json *json_number_string(const double number);

/**
 * Create a JSON boolean instance.
 *
 * @param const int bool_value
 *   The boolean value as int.
 *
 * @return struct json*
 *   Returns the JSON boolean instance; otherwise, NULL.
 */
struct json *json_bool(const int bool_value);

/**
 * Create a JSON null instance.
 *
 * @return struct json*
 *   Returns the JSON null instance; otherwise, NULL.
 */
struct json *json_null();

/**
 * Create a empty JSON object instance.
 *
 * @return struct json*
 *   Returns the JSON object instance; otherwise, NULL.
 */
struct json *json_empty_object();

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
struct json *json_object(const char *key, void *value);

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
struct json *json_object_string(const char *key, const char *string);

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
struct json *json_object_number(const char *key, const double number);

/**
 * Creates a JSON number string object instance.
 *
 * This function creates a JSON object that represents a key-value pair where the value is a number string.
 *
 * @param const char* key
 *   The key for the JSON object.
 * @param const double number
 *   The numeric value for the JSON object.
 *
 * @return struct json*
 *   Returns a pointer to the created JSON object instance on success, or NULL on failure.
 */
struct json *json_object_number_string(const char *key, const double number);

/**
 * Create a JSON array instance.
 *
 * @return struct json*
 *   Returns the JSON array instance; otherwise, NULL.
 */
struct json *json_array();

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
void json_push(struct json *container, struct json *child);

#endif /* JSON_BUILDER_H */
