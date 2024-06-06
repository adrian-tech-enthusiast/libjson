#ifndef JSON_DECODER_H
#define JSON_DECODER_H

#include "../string/tokenizer.h"

/**
 * Decodes the given a JSON encoded string and converts it into a JSON object.
 *
 * @param struct string_tokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json(struct string_tokenizer* tokenizer);

/**
 * Decodes a JSON string value.
 *
 * @param struct string_tokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_string(struct string_tokenizer* tokenizer);

/**
 * Decodes a JSON number value.
 *
 * @param struct string_tokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_number(struct string_tokenizer* tokenizer);

/**
 * Decodes a JSON boolean value.
 *
 * @param struct string_tokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_boolean(struct string_tokenizer* tokenizer);

/**
 * Decodes a JSON null value.
 *
 * @param struct string_tokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_null(struct string_tokenizer* tokenizer);

/**
 * Decodes a JSON array value.
 *
 * @param struct string_tokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_array(struct string_tokenizer* tokenizer);

/**
 * Decodes a JSON object value.
 *
 * @param struct string_tokenizer* tokenizer
 *   The string tokenizer instance.
 *
 * @return struct json*
 *   Returns the decoded JSON object instance; otherwise, NULL.
 */
struct json* _decode_json_object(struct string_tokenizer* tokenizer);

#endif
