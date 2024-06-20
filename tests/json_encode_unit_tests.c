#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/json.h"
#include "json_encode_unit_tests.h"

/**
 * {@inheritdoc}
 */
int run_json_encode_unit_tests() {
  // Create the following JSON object:
  // {
  //   "employee": {
  //     "name": "John",
  //     "age": 30,
  //     "city": "New York"
  //   }
  // }
  struct json *employee = json_object("employee", NULL);
  if (employee == NULL) {
    fprintf(stderr, "Failed to create JSON object.\n");
    return EXIT_FAILURE;
  }

  // Add properties to the employee object.
  json_push(employee, json_object_string("name", "John"));
  json_push(employee, json_object_number("age", 30));
  json_push(employee, json_object_string("city", "New York"));

  // Encode the employee JSON object.
  char expected_json_string[] = "{\"employee\":{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}}";
  char *encoded_json_string = json_encode(employee);
  if (encoded_json_string == NULL) {
    fprintf(stderr, "Failed to encode JSON object.\n");
    json_destroy(employee);
    return EXIT_FAILURE;
  }

  // Compare the encoded JSON string with the expected JSON string.
  if (strcmp(encoded_json_string, expected_json_string) != 0) {
    fprintf(stderr, "Encoded JSON value '%s' does not match expected JSON value '%s'.\n", encoded_json_string, expected_json_string);
    free(encoded_json_string);
    json_destroy(employee);
    return EXIT_FAILURE;
  }

  // Print results.
  printf("Encoded JSON string:  '%s'.\n", encoded_json_string);
  printf("Expected JSON string: '%s'.\n", expected_json_string);

  // Clean up allocated memory.
  free(encoded_json_string);
  json_destroy(employee);

  return EXIT_SUCCESS;
}
