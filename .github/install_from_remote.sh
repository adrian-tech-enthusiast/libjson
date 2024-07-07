#!/bin/bash

# @file install_from_remote.sh
# @brief Script download and install a shared library and its header file from GitHub..
#
# This script automates the installation of shared libraries and header files
# into system directories for local development or deployment. It utilizes helper
# functions from "helper.sh" to perform these tasks.


# Install 'libstr' library dependency locally from remote(Github repo).
install_library_from_remote "adrian-tech-enthusiast" "libstr" "v1.0.1" "libstr.so" "strutils.h";

# Install 'libfile' library dependency locally from remote(Github repo).
install_library_from_remote "adrian-tech-enthusiast" "libfile" "v1.0.0" "libfile.so" "filehelper.h";
