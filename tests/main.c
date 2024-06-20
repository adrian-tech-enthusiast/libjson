#include <stdio.h>
#include <stdlib.h>
#include "json_decode_unit_tests.h"
#include "json_encode_unit_tests.h"

/**
 * Main Unit Testing controller function.
 *
 * @param int argc
 *   The number of arguments passed by the user in the command line.
 * @param array argv
 *   Array of char, the arguments names.
 *
 * @return int
 *   The constant that represent the exit status.
 */
int main(int argc, char const *argv[]) {
  printf("------------------------------ Unit Test: json_decode() ------------------------------\n");
  if (run_json_decode_unit_tests() == EXIT_FAILURE) {
    // Unit tests failed.
    return EXIT_FAILURE;
  }
  printf("\n------------------------------ Unit Test: json_encode() ------------------------------\n");
  if (run_json_encode_unit_tests() == EXIT_FAILURE) {
    // Unit tests failed.
    return EXIT_FAILURE;
  }
  printf("\n");
  // Unit tests succeeded.
  return EXIT_SUCCESS;
}
