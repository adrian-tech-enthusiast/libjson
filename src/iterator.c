#include <stdlib.h>
#include <string.h>
#include <strutils.h>
#include "../include/json.h"

/**
 * {@inheritdoc}
 */
struct json* json_find_node(struct json* object, const char* path, const char delimiter) {
   // Clone the path.
   char* route = strdup(path);
   if (route == NULL) {
      return NULL;
   }
   // Validates the object type.
   if (object->type != JSON_object) {
      free(route);
      return NULL;
   }
   // Set the node.
   struct json* node = object;
   // Get the current key.
   char* key = strtok(route, &delimiter);
   if (key == NULL) {
      free(route);
      return NULL;
   }
   // Find the object with the target key.
   while (key != NULL) {
      // Check if the current object has the target key.
      while (node != NULL && strcmp(node->key, key) != 0) {
         node = node->next;
      }
      // Set the cursor to the node value.
      if (node != NULL) {
         node = (struct json*)node->value;
      }
      // Check if the key was found.
      if (node == NULL) {
         // The given path does not exist in the JSON object.
         free(route);
         return NULL;
      }
      // Move to the next path token.
      key = strtok(NULL, &delimiter);
   }
   // Free the route.
   free(route);
   // Return the target node.
   return node;
}

/**
 * {@inheritdoc}
 */
struct json* json_find_node_by_index(struct json* object, const int index) {
   // JSON require all the index to be strings.
   char* path = itos(index);
   if (path == NULL) {
      return NULL;
   }
   // Find the node.
   struct json* node = json_find_node(object, path, '.');
   // Free the memory.
   free(path);
   path = NULL;
   // Return the JSON node.
   return node;
}
