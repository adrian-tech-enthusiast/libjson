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

# Go to the project folder.
cd $PROJECT_PATH;

# Clean up build and bin folder.
rm -rf $BUILD_PATH && mkdir -p $BUILD_PATH;
rm -rf $BIN_PATH && mkdir -p $BIN_PATH;

# Install library dependencies.
if ! [ -f /usr/local/lib/libstr.so ]; then
  echo "Installing libstr.so";
  sudo curl -L "https://github.com/adrian-tech-enthusiast/libstr/releases/download/v1.0.1/libstr.so" -o /usr/local/lib/libstr.so;
  sudo ldconfig;
  ldconfig -p | grep str;
  sudo curl -L "https://raw.githubusercontent.com/adrian-tech-enthusiast/libstr/v1.0.1/include/strutils.h" -o /usr/local/include/strutils.h;
fi

if ! [ -f /usr/local/lib/libfile.so ]; then
  echo "Installing libfile.so";
  sudo curl -L "https://github.com/adrian-tech-enthusiast/libfile/releases/download/v1.0.0/libfile.so" -o /usr/local/lib/libfile.so
  sudo ldconfig;
  ldconfig -p | grep file;
  sudo curl -L "https://raw.githubusercontent.com/adrian-tech-enthusiast/libfile/v1.0.0/include/filehelper.h" -o /usr/local/include/filehelper.h;
fi

# Build the project.
cd $BUILD_PATH;

gcc -O3 -march=native -g -fpic -save-temps -Wall -Werror -pedantic-errors -o $APP_NAME $FILES_TO_COMPILE -lfile -lstr;
if [ $? -ne 0 ]
then
  echo "Compile Failed!"
  exit 1
fi

# Give executable permissions to the APP.
if [ -f "$APP_FILE" ]; then
  chmod +w $APP_FILE;
fi

# Get list of object files in the build directory.
OBJ_FILES=$(find . -type f -name "*.o" -not -path '*/\.*' | sed 's/^\.\///g' | sort);

# Create single shared library file from the object module(s)
gcc -shared -Wl,-soname,$BASE_NAME.so -o $BASE_NAME.so $OBJ_FILES;

# Create the static library (archive) from the the object files using the ar tool.
ar rcs $BASE_NAME.a $OBJ_FILES;

# Move executables and libraries files to the bin directory.
mv $APP_NAME $BIN_PATH;
mv $BASE_NAME.so $BIN_PATH;
mv $BASE_NAME.a $BIN_PATH;

# Go back to the root of the project.
cd $PROJECT_PATH;

## Test the APP execution.
$BIN_PATH/$APP_NAME;
