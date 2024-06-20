# LibJSON: A Lightweight and Efficient JSON Parsing Library Written in C.

LibJSON is a powerful C library designed for efficient manipulation of JSON objects. It provides functionalities to create, manipulate, encode, and decode JSON data, making it simple and efficient for basic and advanced JSON operations.

### Key Features

- **JSON Object Creation**: Create JSON objects of various types (string, number, object, array, boolean, null).
- **JSON Encoding**: Encode JSON objects into JSON strings.
- **JSON Decoding**: Decode JSON strings into JSON objects.
- **Traversal with Iterators**: Traverse JSON objects using iterators.
- **Dynamic Object Building**: Build JSON objects dynamically using builder functions.

## Prerequisites

Before installing LibJSON, ensure you have the following libraries installed:

1. [**Lib Strutils (libstr)**](https://github.com/adrian-tech-enthusiast/libstr?tab=readme-ov-file#installation) [v1.0.1](https://github.com/adrian-tech-enthusiast/libstr/releases/tag/v1.0.1) or later - Offers a robust collection of functions designed for efficient manipulation of character arrays.
2. [**Lib File (Lib)**](https://github.com/adrian-tech-enthusiast/libfile?tab=readme-ov-file#installation) [v1.0.0](https://github.com/adrian-tech-enthusiast/libfile/releases/tag/v1.0.0) or later - provides easy-to-use helper functions for file operations.

### Installation

To install LibJSON, follow these steps:

1. Check the latest stable version on the [releases page](https://github.com/adrian-tech-enthusiast/libjson/releases). At the time of writing, the current stable version is 1.0.0.

2. Download the shared library (`libjson.so` for Unix/Linux) to `/usr/local/lib`:

    ```bash
    sudo curl -L "https://github.com/adrian-tech-enthusiast/libjson/releases/download/v1.0.0/libjson.so" -o /usr/local/lib/libjson.so
    ```

3. Update the system's dynamic loader cache:

    ```bash
    sudo ldconfig;
    ```

4. Download the library header file (`json.h`) to `/usr/local/include`:

    ```bash
    sudo curl -L "https://raw.githubusercontent.com/adrian-tech-enthusiast/libjson/v1.0.0/include/json.h" -o /usr/local/include/json.h
    ```

5. Include `json.h` in your C project:

    ```c
    #include <stdio.h>  /* standard input/output functions */
    #include <json.h> /* C JSON Library functions */
    ```

6. Compile your C program with the LibJSON library::

    ```bash
    gcc -o my_program my_program.c -ljson
    ```

### Usage

To use this library, include the necessary header (`json.h`) in your C project and link against the library file.

Here's a simple example demonstrating how to create, encode, and decode a JSON object:

```c
#include <stdio.h>
#include "json.h"

int main() {
  // Create the following JSON object:
  // {
  //   "employee": {
  //     "name": "John",
  //     "age": 30,
  //     "city": "New York"
  //   }
  // }
  struct json *employee = json_object("employee", NULL);
  json_push(employee, json_object_string("name", "John"));
  json_push(employee, json_object_number("age", 30));
  json_push(employee, json_object_string("city", "New York"));

  // Encode the JSON object,
  char *encoded_json = json_encode(employee);
  printf("Encoded JSON: %s\n", encoded_json);

  // Decode the JSON string.
  struct json *decoded_object = json_decode(encoded_json);

  // Clean up allocated memory.
  json_destroy(employee);
  json_destroy(decoded_object);
  free(encoded_json);

  return 0;
}
```

### Contributions

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any
contributions you make are greatly appreciated.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### License

This library is licensed under the `GNU General Public License v3.0` License. See the LICENSE file for details.

### Contact

For any inquiries, please contact Mr. Adrián Morelos at adrian.tech.enthusiast@gmail.com.

Enjoy using LibJSON for efficient JSON handling in your C projects! 🚀
