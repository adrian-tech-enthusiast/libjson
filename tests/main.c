#include <stdlib.h>
#include "sigmoid_unit_tests.h"
#include "tanh_unit_tests.h"
#include "relu_unit_tests.h"
#include "softmax_unit_tests.h"
#include "identity_unit_tests.h"

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
  if (run_sigmoid_unit_tests() == EXIT_FAILURE) {
    // Unit tests failed.
    return EXIT_FAILURE;
  }
  if (run_tanh_unit_tests() == EXIT_FAILURE) {
    // Unit tests failed.
    return EXIT_FAILURE;
  }
  if (run_softmax_unit_tests() == EXIT_FAILURE) {
    // Unit tests failed.
    return EXIT_FAILURE;
  }
  if (run_relu_unit_tests() == EXIT_FAILURE) {
    // Unit tests failed.
    return EXIT_FAILURE;
  }
  if (run_identity_unit_tests() == EXIT_FAILURE) {
    // Unit tests failed.
    return EXIT_FAILURE;
  }
  // Unit tests succeeded.
  return EXIT_SUCCESS;
}
