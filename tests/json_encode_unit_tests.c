#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/json.h"
#include "json_encode_unit_tests.h"

int run_json_encode_compare(char *expected, char *encoded) {
  // Compare the encoded empty JSON string with the expected empty JSON string.
  if (strcmp(encoded, expected) != 0) {
    fprintf(stderr, "Encoded empty JSON value '%s' does not match expected empty JSON value '%s'.\n", encoded, expected);
    return EXIT_FAILURE;
  }
  // Print results.
  printf("Encoded JSON string:  '%s'.\n", encoded);
  printf("Expected JSON string: '%s'.\n", expected);
  printf("--------------------------------------------------------------------------------------\n");
  return EXIT_SUCCESS;
}

int run_json_encode_unit_tests_a() {
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
  int result = run_json_encode_compare(expected_json_string, encoded_json_string);

  // Clean up allocated memory.
  free(encoded_json_string);
  json_destroy(employee);

  return result;
}

int run_json_encode_unit_tests_b() {
  // Create the following JSON object: {}.
  struct json *empty_json = json_empty_object();
  if (empty_json == NULL) {
    fprintf(stderr, "Failed to create empty JSON object.\n");
    return EXIT_FAILURE;
  }

  // Encode the employee JSON object.
  char expected_json_empty_string[] = "{}";
  char *encoded_json_empty_string = json_encode(empty_json);
  if (encoded_json_empty_string == NULL) {
    fprintf(stderr, "Failed to encode JSON object.\n");
    json_destroy(empty_json);
    return EXIT_FAILURE;
  }

  // Compare the encoded empty JSON string with the expected empty JSON string.
  int result = run_json_encode_compare(expected_json_empty_string, encoded_json_empty_string);

  // Clean up allocated memory.
  free(encoded_json_empty_string);
  json_destroy(empty_json);

  return result;
}

int run_json_encode_unit_tests_c() {
  // Create the following JSON object:
  // {
  //   "empty_property": {}
  // }
  struct json *empty_property = json_object("empty_property", NULL);
  if (empty_property == NULL) {
    fprintf(stderr, "Failed to create empty JSON object.\n");
    return EXIT_FAILURE;
  }
  // Add properties to the empty_property object.
  json_push(empty_property, json_empty_object());
  // Encode the employee JSON object.
  char expected[] = "{\"empty_property\":{}}";
  char *encoded = json_encode(empty_property);
  if (encoded == NULL) {
    fprintf(stderr, "Failed to encode JSON object.\n");
    json_destroy(empty_property);
    return EXIT_FAILURE;
  }

  // Compare the encoded empty JSON string with the expected empty JSON string.
  int result = run_json_encode_compare(expected, encoded);

  // Clean up allocated memory.
  free(encoded);
  json_destroy(empty_property);

  return result;
}

int run_json_encode_unit_tests_d() {
  // Create the following JSON object:
  // [
  //   [1,2,3,4],
  //   [5,6,7,8],
  // ]
  struct json *container = json_array();
  if (container == NULL) {
    fprintf(stderr, "Failed to create empty JSON array.\n");
    return EXIT_FAILURE;
  }
  struct json *row_1 = json_array();
  json_push(row_1, json_number(1));
  json_push(row_1, json_number(2));
  json_push(row_1, json_number(3));
  json_push(row_1, json_number(4));

  struct json *row_2 = json_array();
  json_push(row_2, json_number(5));
  json_push(row_2, json_number(6));
  json_push(row_2, json_number(7));
  json_push(row_2, json_number(8));

  // Add properties to the empty_property object.
  json_push(container, row_1);
  json_push(container, row_2);
  // Encode the employee JSON object.
  char expected[] = "[[1,2,3,4],[5,6,7,8]]";
  char *encoded = json_encode(container);
  if (encoded == NULL) {
    fprintf(stderr, "Failed to encode JSON object.\n");
    json_destroy(container);
    return EXIT_FAILURE;
  }

  // Compare the encoded JSON string with the expected JSON string.
  int result = run_json_encode_compare(expected, encoded);

  // Clean up allocated memory.
  free(encoded);
  json_destroy(container);

  return result;
}

/**
 * {@inheritdoc}
 */
int run_json_encode_unit_tests() {
  if (run_json_encode_unit_tests_a() == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }
  if (run_json_encode_unit_tests_b() == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }
  if (run_json_encode_unit_tests_c() == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }
  if (run_json_encode_unit_tests_d() == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
