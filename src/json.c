#include <stdlib.h>
#include "decoder.h"
#include "encoder.h"
#include "../include/json.h"

/**
 * {@inheritdoc}
 */
struct json* json_create(enum JSONDataType type, void* value) {
   // Allocate JSON object memory.
   size_t size = sizeof(struct json);
   struct json* json_object = (struct json*)malloc(size);
   if (json_object == NULL) {
      return NULL;
   }
   // Init JSON object properties.
   json_object->next = NULL;
   json_object->prev = NULL;
   json_object->type = type;
   json_object->key = NULL;
   json_object->value = value;
   // Return the JSON object.
   return json_object;
}

/**
 * {@inheritdoc}
 */
void json_destroy(struct json* object) {
   if (object == NULL) {
      // Uninitialized JSON object.
      return;
   }
   if (object->key != NULL) {
      free(object->key);
      object->key = NULL;
   }
   if (object->value != NULL) {
      free(object->value);
      object->value = NULL;
   }
   if (object->next != NULL) {
      json_destroy(object->next);
   }
   free(object);
   object = NULL;
}

/**
 * {@inheritdoc}
 */
struct json* json_decode(const char* json_string) {
   // Init the String Tokenizer instance.
   struct StringTokenizer *tokenizer = st_create((char*)json_string);
   if (tokenizer == NULL) {
      return NULL;
   }
   // Try to decode the JSON string.
   struct json* json_object = _decode_json(tokenizer);
   // Free the tokenizer memory.
   st_destroy(tokenizer);
   // Return the decoded JSON object.
   return json_object;
}

/**
 * {@inheritdoc}
 */
char* json_encode(struct json* object) {
   // Init the String Tokenizer instance.
   struct StringTokenizer *tokenizer = st_create_empty(100);
   if (tokenizer == NULL) {
      return NULL;
   }
   // Try to encode the JSON object.
   if (_encode_json(object, tokenizer) == 0) {
      // Free the tokenizer memory.
      st_destroy(tokenizer);
      return NULL;
   }
   char* json_string = tokenizer->string;
   // Free the tokenizer memory.
   st_destroy(tokenizer);
   // Return the decoded JSON object.
   return json_string;
}
