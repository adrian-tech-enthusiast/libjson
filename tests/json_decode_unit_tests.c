#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/json.h"
#include "json_decode_unit_tests.h"

/**
 * Helper function to retrieve the value of a JSON node.
 *
 * This function finds a JSON node specified by the given path within the JSON object.
 * If the node or its value is not found, an error message is printed to stderr.
 *
 * @param const struct json *json_object
 *   The JSON object from which to retrieve the node value.
 * @param const char *path
 *   The path to the desired JSON node, using '.' as a separator for nested nodes.
 *
 * @return void *
 *   The pointer to the value of the JSON node, or NULL if the node or its value is not found.
 */
static void *get_json_node_value(const struct json *json_object, const char *path) {
  struct json *node = json_find_node((struct json *)json_object, path, '.');
  if (node == NULL || node->value == NULL) {
    fprintf(stderr, "Failed to find or decode '%s' in JSON.\n", path);
    return NULL;
  }
  return node->value;
}

/**
 * Helper function to check JSON string values.
 *
 * This function retrieves the JSON node value for the specified path and compares it
 * with the expected string value. If the values match, it prints the decoded value.
 * If they do not match, an error message is printed to stderr.
 *
 * @param const struct json *json_object
 *   The JSON object to check against.
 * @param const char *path
 *   The path to the JSON node containing the string value.
 * @param expected_value
 *   The expected string value of the JSON node.
 *
 * @return int
 *   EXIT_SUCCESS if the value matches the expected, otherwise EXIT_FAILURE.
 */
static int check_json_string(const struct json *json_object, const char *path, const char *expected_value) {
  void *raw_value = get_json_node_value(json_object, path);
  if (raw_value == NULL) {
    return EXIT_FAILURE;
  }
  const char *decoded_value = (const char *)raw_value;
  if (strcmp(decoded_value, expected_value) != 0) {
    fprintf(stderr, "Decoded value '%s' for '%s' does not match expected value '%s'.\n", decoded_value, path, expected_value);
    return EXIT_FAILURE;
  }
  printf("Decoded value '%s' is: %s\n", path, decoded_value);
  return EXIT_SUCCESS;
}

/**
 * Helper function to check JSON double values.
 *
 * This function retrieves the JSON node value for the specified path and compares it
 * with the expected double value. If the values match, it prints the decoded value.
 * If they do not match, an error message is printed to stderr.
 *
 * @param const struct json *json_object
 *   The JSON object to check against.
 * @param const char *path
 *   The path to the JSON node containing the double value.
 * @param expected_value
 *   The expected double value of the JSON node.
 *
 * @return int
 *   EXIT_SUCCESS if the value matches the expected, otherwise EXIT_FAILURE.
 */
static int check_json_double(const struct json *json_object, const char *path, double expected_value) {
  void *raw_value = get_json_node_value(json_object, path);
  if (raw_value == NULL) {
    return EXIT_FAILURE;
  }
  double decoded_value = *((double *)raw_value);
  if (decoded_value != expected_value) {
    fprintf(stderr, "Decoded value '%lf' for '%s' does not match expected value '%lf'.\n", decoded_value, path, expected_value);
    return EXIT_FAILURE;
  }
  printf("Decoded value '%s' is: %lf\n", path, decoded_value);
  return EXIT_SUCCESS;
}

/**
 * {@inheritdoc}
 */
int run_json_decode_unit_tests() {
  // JSON string to be decoded.
  char json_string[] = "{\"employee\":{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}}";

  // Print the raw JSON string.
  printf("Raw JSON: %s\n", json_string);

  // Decode the JSON string.
  struct json *json_object = json_decode(json_string);
  if (json_object == NULL) {
    fprintf(stderr, "Failed to decode JSON.\n");
    return EXIT_FAILURE;
  }

  // Check employee name
  if (check_json_string(json_object, "employee.name", "John") == EXIT_FAILURE) {
    json_destroy(json_object);
    return EXIT_FAILURE;
  }
  // Check employee age
  if (check_json_double(json_object, "employee.age", 30.0) == EXIT_FAILURE) {
    json_destroy(json_object);
    return EXIT_FAILURE;
  }
  // Check employee city
  if (check_json_string(json_object, "employee.city", "New York") == EXIT_FAILURE) {
    json_destroy(json_object);
    return EXIT_FAILURE;
  }

  // Clean up allocated memory.
  json_destroy(json_object);

  return EXIT_SUCCESS;
}
