#include <stdlib.h>
#include "json.h"
#include "../file/file_get_contents.h"

/**
 * {@inheritdoc}
 */
struct json* json_open(const char* filepath) {
   // Read the JSON file content.
   char* json_string = file_get_contents(filepath);
   if (json_string == NULL) {
      return NULL;
   }
   // Decode the JSON string.
   struct json* json_object = json_decode(json_string);
   // Free the memory.
   free(json_string);
   // Return the JSON object.
   return json_object;
}
