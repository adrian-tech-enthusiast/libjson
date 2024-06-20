#ifndef JSON_DECODE_UNIT_TESTS_H
#define JSON_DECODE_UNIT_TESTS_H

/**
 * Runs the JSON decode unit tests.
 *
 * This function decodes a JSON string representing employee data, checks specific attributes
 * (name, age, and city) against expected values, and prints the decoded values if they match.
 * If decoding fails or any attribute does not match the expected value, appropriate error messages
 * are printed to stderr.
 *
 * @return int
 *   EXIT_SUCCESS if all tests pass, otherwise EXIT_FAILURE.
 */
int run_json_decode_unit_tests();

#endif
