#ifndef JSON_ENCODER_H
#define JSON_ENCODER_H

#include <strutils.h> 
#include "../include/json.h"

/**
 * Encodes the given a JSON object and converts it into a JSON string.
 *
 * @param struct json* json_object
 *   The JSON object to decode.
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return int
 *   Returns 1 when the encoding succeeded; otherwise, 0.
 */
int _encode_json(struct json* json_object, struct StringTokenizer* tokenizer);

/**
 * Encodes a JSON string value.
 *
 * @param struct json* json_object
 *   The JSON object to decode.
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return int
 *   Returns 1 when the encoding succeeded; otherwise, 0.
 */
int _encode_json_string(struct json* json_object, struct StringTokenizer* tokenizer);

/**
 * Encodes a JSON number value.
 *
 * @param struct json* json_object
 *   The JSON object to decode.
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return int
 *   Returns 1 when the encoding succeeded; otherwise, 0.
 */
int _encode_json_number(struct json* json_object, struct StringTokenizer* tokenizer);

/**
 * Encodes a JSON boolean value.
 *
 * @param struct json* json_object
 *   The JSON object to decode.
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return int
 *   Returns 1 when the encoding succeeded; otherwise, 0.
 */
int _encode_json_boolean(struct json* json_object, struct StringTokenizer* tokenizer);

/**
 * Encodes a JSON null value.
 *
 * @param struct json* json_object
 *   The JSON object to decode.
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return int
 *   Returns 1 when the encoding succeeded; otherwise, 0.
 */
int _encode_json_null(struct json* json_object, struct StringTokenizer* tokenizer);

/**
 * Encodes a JSON array value.
 *
 * @param struct json* json_object
 *   The JSON object to decode.
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return int
 *   Returns 1 when the encoding succeeded; otherwise, 0.
 */
int _encode_json_array(struct json* json_object, struct StringTokenizer* tokenizer);

/**
 * Encodes a JSON object value.
 *
 * @param struct json* json_object
 *   The JSON object to decode.
 * @param struct StringTokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return int
 *   Returns 1 when the encoding succeeded; otherwise, 0.
 */
int _encode_json_object(struct json* json_object, struct StringTokenizer* tokenizer);

#endif  /* JSON_ENCODER_H */
