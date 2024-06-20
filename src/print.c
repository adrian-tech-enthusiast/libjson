#include <stdio.h>
#include <stdlib.h>
#include <strutils.h>
#include "print.h"

/**
 * {@inheritdoc}
 */
void json_string_print(const char* json_string) {
   // Init the String Tokenizer instance.
   struct StringTokenizer *tokenizer = st_create((char*)json_string);
   if (tokenizer == NULL) {
      return;
   }
   // Print the JSON file without spaces.
   char token = st_current_token(tokenizer);
   while (token != '\0') {
      // Print the current token/character.
      printf("%c", token);
      // Find the next valid token/character.
      st_next_token(tokenizer);
      // Get the next token/character.
      token = st_current_token(tokenizer);
   }
   // Free the tokenizer memory.
   st_destroy(tokenizer);
}

/**
 * {@inheritdoc}
 */
void json_object_print(struct json* object) {
   // Encode the JSON object.
   char* json_string = json_encode(object);
   if (json_string == NULL) {
      printf("Failed to encode JSON.\n");
      return NULL;
   }
   // Print the JSON string.
   printf("Encode JSON: ");
   json_string_print(json_string);
   printf("\n");
   // Free JSOn string memory.
   free(json_string);
}
