#ifndef JSON_DECODER_H
#define JSON_DECODER_H

#include <strutils.h>
#include "../include/json.h"

/**
 * Decodes the given a JSON encoded string and converts it into a JSON object.
 *
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json(struct StringTokenizer* tokenizer);

/**
 * Decodes a JSON string value.
 *
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_string(struct StringTokenizer* tokenizer);

/**
 * Decodes a JSON number value.
 *
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_number(struct StringTokenizer* tokenizer);

/**
 * Decodes a JSON boolean value.
 *
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_boolean(struct StringTokenizer* tokenizer);

/**
 * Decodes a JSON null value.
 *
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_null(struct StringTokenizer* tokenizer);

/**
 * Decodes a JSON array value.
 *
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_array(struct StringTokenizer* tokenizer);

/**
 * Decodes a JSON object value.
 *
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_object(struct StringTokenizer* tokenizer);

#endif
