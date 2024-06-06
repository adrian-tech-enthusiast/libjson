#include "decoder.h"
#include "json.h"

/**
 * {@inheritdoc}
 */
struct json* _decode_json(struct string_tokenizer* tokenizer) {
   // Get the current token in the tokenizer.
   const char token = st_current_token(tokenizer);
   // Decodes the token based on the different types of JSON values.
   // Check for object token.
   if (token == '{') {
      return _decode_json_object(tokenizer);
   }
   // Check for array token.
   if (token == '[') {
      return _decode_json_array(tokenizer);
   }
   // Check for string double-quote token.
   if (token == '\"') {
      return _decode_json_string(tokenizer);
   }
   // Check for number token.
   if (token == '-' || token >= '0' || token <= '9') {
      return _decode_json_number(tokenizer);
   }
   // Check for boolean tokens(true or false).
   if (token == 't' || token == 'f') {
      return _decode_json_boolean(tokenizer);
   }
   // Check for null token.
   if (token == 'n') {
      return _decode_json_null(tokenizer);
   }
   // Invalid JSON token.
   return NULL;
}

/**
 * {@inheritdoc}
 */
struct json* _decode_json_string(struct string_tokenizer* tokenizer) {
   // Get the substring between the double quotes.
   char* value = st_sub_string(tokenizer, '\"', '\"');
   if (value == NULL) {
      return NULL;
   }
   // Init the JSON object instance.
   struct json* json_object = json_create(JSON_string, value);
   if (json_object == NULL) {
      free(value);
   }
   // String decoding completed.
   return json_object;
}

/**
 * {@inheritdoc}
 */
struct json* _decode_json_boolean(struct string_tokenizer* tokenizer) {
   // Get the current token in the tokenizer.
   const char token = st_current_token(tokenizer);
   // Declare the bool value as int.
   int* value = NULL;
   // Search for boolean true token.
   if (token == 't') {
      value = st_extract_boolean(tokenizer, "true", 1);
   }
   // Search for boolean false token.
   else if (token == 'f') {
      value = st_extract_boolean(tokenizer, "false", 0);
   }
   else {
      // Invalid JSON boolean token.
      return NULL;
   }
   // Check the extracted value.
   if (value == NULL) {
      return NULL;
   }
   // Init the JSON object instance.
   struct json* json_object = json_create(JSON_boolean, value);
   if (json_object == NULL) {
      free(value);
   }
   // Boolean decoding completed.
   return json_object;
}

/**
 * {@inheritdoc}
 */
struct json* _decode_json_null(struct string_tokenizer* tokenizer) {
   // Search for the null string.
   if (st_starts_with(tokenizer, "null") == 0) {
      // Not a null token.
      return NULL;
   }
   // NULL decoding completed.
   return json_create(JSON_null, NULL);
}

/**
 * {@inheritdoc}
 */
struct json* _decode_json_number(struct string_tokenizer* tokenizer) {
   // Extract double value from string.
   double* value = st_extract_double(tokenizer);
   if (value == NULL) {
      return NULL;
   }
   // Init the JSON object instance.
   struct json* json_object = json_create(JSON_number, value);
   if (json_object == NULL) {
      free(value);
   }
   // Number decoding completed.
   return json_object;
}

/**
 * {@inheritdoc}
 */
struct json* _decode_json_array(struct string_tokenizer* tokenizer) {
   // Get the current token in the tokenizer.
   char token = st_current_token(tokenizer);
   // Check the start of the array.
   if (token != '[') {
      // Not an array.
      return NULL;
   }
   // Loop through the comma separated array elements.
   struct json* head = NULL, * current = NULL, * prev = NULL;
   do {
      // Get the next valid token.
      st_next_token(tokenizer);
      token = st_current_token(tokenizer);
      // Decodes the array value.
      current = _decode_json(tokenizer);
      if (current == NULL) {
         return NULL;
      }
      // Get the next valid token.
      st_next_token(tokenizer);
      token = st_current_token(tokenizer);
      // Updates the position of the current element in the linked list.
      if (head == NULL) {
         head = current;
         prev = current;
      }
      else {
         prev->next = current;
         current->prev = prev;
         prev = current;
      }
   } while (token == ',');
   // Check the JSON array closing token.
   if (token != ']') {
      json_destroy(head);
      return NULL;
   }
   // Create the array instance.
   struct json* json_array = json_create(JSON_array, head);
   if (json_array == NULL) {
      free(head);
      return NULL;
   }
   // JSON array decoding completed.
   return json_array;
}

/**
 * {@inheritdoc}
 */
struct json* _decode_json_object(struct string_tokenizer* tokenizer) {
   // Get the current token in the tokenizer.
   char token = st_current_token(tokenizer);
   // Check the start of the object.
   if (token != '{') {
      // Not an object.
      return NULL;
   }
   // Loop through the comma separated array elements.
   struct json* head = NULL, * current = NULL, * prev = NULL;
   do {
      // Move to the next valid token.
      st_next_token(tokenizer);
      token = st_current_token(tokenizer);
      // Extract the object key.
      char* key = st_sub_string(tokenizer, '\"', '\"');
      if (key == NULL) {
         return NULL;
      }
      // Check for the colon (:) character.
      st_next_token(tokenizer);
      token = st_current_token(tokenizer);
      if (token != ':') {
         free(key);
         return NULL;
      }
      // Get the next valid token.
      st_next_token(tokenizer);
      token = st_current_token(tokenizer);
      // Decodes the object value.
      struct json* value = _decode_json(tokenizer);
      if (value == NULL) {
         free(key);
         return NULL;
      }
      // Create the object instance.
      current = json_create(JSON_object, value);
      if (current == NULL) {
         free(key);
         free(value);
         return NULL;
      }
      // Set the object value and the key.
      current->key = key;
      current->value = value;
      // Get the next valid token.
      st_next_token(tokenizer);
      token = st_current_token(tokenizer);
      // Updates the position of the current element in the linked list.
      if (head == NULL) {
         head = current;
         prev = current;
      }
      else {
         prev->next = current;
         current->prev = prev;
         prev = current;
      }
   } while (token == ',');
   // Check the JSON object closing token.
   if (token != '}') {
      json_destroy(head);
      return NULL;
   }
   // JSON object decoding completed.
   return head;
}
