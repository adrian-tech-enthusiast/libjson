#ifndef JSON_ITERATOR_H
#define JSON_ITERATOR_H

#include "json.h"

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
struct json* json_find_node(struct json* object, const char* path, const char delimiter);

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
struct json* json_find_node_by_index(struct json* object, const int index);

#endif
