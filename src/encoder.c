#include <string.h>
#include "encoder.h"

/**
 * {@inheritdoc}
 */
int _encode_json(struct json *json_object, struct StringTokenizer *tokenizer) {
  if (json_object == NULL || tokenizer == NULL) {
    return 0;
  }
  // Encodes the object based on the different types of JSON values.
  // Check for object token.
  if (json_object->type == JSON_object) {
    return _encode_json_object(json_object, tokenizer);
  }
  // Check for array token.
  if (json_object->type == JSON_array) {
    return _encode_json_array(json_object, tokenizer);
  }
  // Check for string double-quote token.
  if (json_object->type == JSON_string) {
    return _encode_json_string(json_object, tokenizer);
  }
  // Check for number token.
  if (json_object->type == JSON_number) {
    return _encode_json_number(json_object, tokenizer);
  }
  // Check for boolean tokens(true or false).
  if (json_object->type == JSON_boolean) {
    return _encode_json_boolean(json_object, tokenizer);
  }
  // Check for null token.
  if (json_object->type == JSON_null) {
    return _encode_json_null(json_object, tokenizer);
  }
  // Invalid JSON token.
  return 0;
}

/**
 * {@inheritdoc}
 */
int _encode_json_string(struct json *json_object, struct StringTokenizer *tokenizer) {
  if (json_object->type != JSON_string) {
    return 0;
  }
  // Append the string value.
  char *value = (char *)json_object->value;
  if (value != NULL && st_append_quoted_string(tokenizer, value) == 0) {
    return 0;
  }
  // String encoding completed.
  return 1;
}

/**
 * {@inheritdoc}
 */
int _encode_json_number(struct json *json_object, struct StringTokenizer *tokenizer) {
  if (json_object->type != JSON_number) {
    return 0;
  }
  // Append the double value.
  double *value = (double *)json_object->value;
  if (value != NULL && st_append_double(tokenizer, value) == 0) {
    return 0;
  }
  // Number encoding completed.
  return 1;
}

/**
 * {@inheritdoc}
 */
int _encode_json_boolean(struct json *json_object, struct StringTokenizer *tokenizer) {
  if (json_object->type != JSON_boolean) {
    return 0;
  }
  // Get the bool value as int.
  int *value = (int *)json_object->value;
  // Append the true token.
  if (*value == 1 && st_append_string(tokenizer, "true") == 1) {
    return 1;
  }
  // Append the false token.
  if (*value == 0 && st_append_string(tokenizer, "false") == 1) {
    return 1;
  }
  // Boolean encoding completed.
  return 1;
}

/**
 * {@inheritdoc}
 */
int _encode_json_null(struct json *json_object, struct StringTokenizer *tokenizer) {
  if (json_object->type != JSON_null) {
    return 0;
  }
  // Append the null token.
  return st_append_string(tokenizer, "null");
}

/**
 * {@inheritdoc}
 */
int _encode_json_array(struct json *json_object, struct StringTokenizer *tokenizer) {
  if (json_object->type != JSON_array) {
    return 0;
  }
  // Append the start array token.
  if (st_append_string(tokenizer, "[") == 0) {
    return 0;
  }
  // Loop through the comma separated array elements.
  struct json *current = json_object->value;
  do {
    // Append the value.
    if (_encode_json(current, tokenizer) == 0) {
      return 0;
    }
    // Append comma(if there is a next sibling).
    if (current->next != NULL && st_append_string(tokenizer, ",") == 0) {
      return 0;
    }
    // Move forward to the next sibling array.
    current = current->next;
  } while (current != NULL);
  // Append the end array token.
  if (st_append_string(tokenizer, "]") == 0) {
    return 0;
  }
  // JSON array encoding completed.
  return 1;
}

/**
 * {@inheritdoc}
 */
int _encode_json_object(struct json *json_object, struct StringTokenizer *tokenizer) {
  if (json_object->type != JSON_object) {
    return 0;
  }
  // Append the start object token.
  if (st_append_string(tokenizer, "{") == 0) {
    return 0;
  }
  // Loop through the comma separated array elements.
  struct json *current = json_object;
  do {
    if (current->key != NULL && current->value != NULL) {
      // Append the key.
      if (st_append_quoted_string(tokenizer, current->key) == 0) {
        return 0;
      }
      // Append the colon (:) token.
      if (st_append_string(tokenizer, ":") == 0) {
        return 0;
      }
      // Append the value.
      if (_encode_json(current->value, tokenizer) == 0) {
        return 0;
      }
    }
    // Append comma(if there is a next sibling).
    if (current->next != NULL && st_append_string(tokenizer, ",") == 0) {
      return 0;
    }
    // Move forward to the next sibling object.
    current = current->next;
  } while (current != NULL);
  // Append the end object token.
  if (st_append_string(tokenizer, "}") == 0) {
    return 0;
  }
  // JSON object encoding completed.
  return 1;
}
