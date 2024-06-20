#include <stdlib.h>
#include <filehelper.h>
#include "save.h"

/**
 * {@inheritdoc}
 */
int json_save(struct json* json_object, const char* filepath) {
   // Encode the JSON object.
   char* json_string = json_encode(json_object);
   if (json_string == NULL) {
      return NULL;
   }
   // Save the JSON string into the given file path.
   return file_put_contents(filepath, json_string);
}
