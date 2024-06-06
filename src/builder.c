#include <stdlib.h>
#include <string.h>
#include "builder.h"
#include "json.h"

/**
 * {@inheritdoc}
 */
struct json* json_string(const char* string) {
   // Build the JSON string instance.
   char* value = strdup(string);
   if (value == NULL) {
      return NULL;
   }
   struct json* object = json_create(JSON_string, value);
   if (object == NULL) {
      free(value);
      return NULL;
   }
   return object;
}

/**
 * {@inheritdoc}
 */
struct json* json_number(const double number) {
   // Build the JSON double instance.
   size_t size = sizeof(double);
   double* value = (double*)malloc(size);
   *value = number;
   struct json* object = json_create(JSON_number, value);
   if (object == NULL) {
      free(value);
      return NULL;
   }
   return object;
}

/**
 * {@inheritdoc}
 */
struct json* json_bool(const int bool_value) {
   // Build the JSON boolean instance.
   int* value = (int*)malloc(sizeof(int));
   *value = bool_value;
   struct json* object = json_create(JSON_boolean, value);
   if (object == NULL) {
      free(value);
      return NULL;
   }
   return object;
}

/**
 * {@inheritdoc}
 */
struct json* json_null() {
   return json_create(JSON_null, NULL);
}

/**
 * {@inheritdoc}
 */
struct json* json_array() {
   return json_create(JSON_array, NULL);
}

/**
 * {@inheritdoc}
 */
struct json* json_object(const char* key, void* value) {
   struct json* object = json_create(JSON_object, NULL);
   if (object == NULL) {
      return NULL;
   }
   char* object_key = strdup(key);
   if (object_key == NULL) {
      return NULL;
   }
   object->key = object_key;
   object->value = value;
   return object;
}

/**
 * {@inheritdoc}
 */
struct json* json_object_string(const char* key, const char* string) {
   // Build the JSON object.
   struct json* object = json_object(key, NULL);
   if (object == NULL) {
      return NULL;
   }
   // Add the JSON string value.
   object->value = json_string(string);
   if (object->value == NULL) {
      free(object);
      return NULL;
   }
   return object;
}

/**
 * {@inheritdoc}
 */
struct json* json_object_number(const char* key, const double number) {
   // Build the JSON object.
   struct json* object = json_object(key, NULL);
   if (object == NULL) {
      return NULL;
   }
   // Add the JSON number value.
   object->value = json_number(number);
   if (object->value == NULL) {
      free(object);
      return NULL;
   }
   return object;
}

/**
 * {@inheritdoc}
 */
void json_push(struct json* container, struct json* child) {
   if (container->value == NULL) {
      container->value = child;
      return;
   }
   // Set iterator.
   struct json* iterator = (struct json*)container->value;
   // Add the child to the sibling list.
   while (iterator->next != NULL) {
      iterator = iterator->next;
   }
   // Add the child to the end of the sibling list.
   iterator->next = child;
   child->prev = iterator;
}
