#!/usr/bin/sh

# Global Settings.
BASE_NAME='libjson';
PROJECT_PATH=$(pwd);
CODE_SEARCH_PATHS="$PROJECT_PATH/include $PROJECT_PATH/src $PROJECT_PATH/tests"; # The subdirectories that will contain all you source files (*.h, *.hpp, *.c, *.cpp, etc.)
BUILD_PATH="$PROJECT_PATH/build"; # This is the subdirectory where the compiler will create the binary files and the final executable.
BIN_PATH="$PROJECT_PATH/bin";
APP_NAME="$BASE_NAME.app";
APP_FILE="$BUILD_PATH/$APP_NAME";

# Get the code files to compile.
HEADER_FILES_TO_COMPILE=$(find $CODE_SEARCH_PATHS -maxdepth 3 -type f -name "*.h" -not -path '*/\.*' | sed 's/^\.\///g' | sort);
SOURCE_FILES_TO_COMPILE=$(find $CODE_SEARCH_PATHS -maxdepth 3 -type f -name "*.c" -not -path '*/\.*' | sed 's/^\.\///g' | sort);
FILES_TO_COMPILE="$HEADER_FILES_TO_COMPILE $SOURCE_FILES_TO_COMPILE";

# Build the project.
cd $BUILD_PATH;

cat $FILES_TO_COMPILE >> unified.c;