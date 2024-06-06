#ifndef JSON_H
#define JSON_H

/**
 * Supported JSON Data Types.
 *
 * In JSON, values must be one of the following data types:
 */
enum JSONDataType {
   JSON_string,
   JSON_number,
   JSON_object,
   JSON_array,
   JSON_boolean,
   JSON_null
};

/**
 * The data struct definition for an individual JSON object gate.
 */
struct json {

   /**
    * Pointer to the next JSON object in the chain.
    *
    * Allow you to walk array/object chains.
    *
    * @var struct json* next.
    */
   struct json* next;

   /**
    * Pointer to the prev JSON object in the chain.
    *
    * Allow you to walk array/object chains.
    *
    * @var struct json* prev.
    */
   struct json* prev;

   /**
    * The type of data that is stored in the current entry/node.
    *
    * @see enum JSONDataTypes.
    *
    * @var struct json* type.
    */
   int type;

   /**
    * The key for the current entry/node.
    *
    * @var char* key.
    */
   char* key;

   /**
    * The value for the current entry/node.
    *
    * @var char* value.
    */
   void* value;

};

/**
 * Takes a JSON encoded string and converts it into a JSON object.
 *
 * @param const char* json
 *   The json string being decoded.
 *
 * @return struct json*
 *   The pointer to the JSON object, otherwise NULL.
 */
struct json* json_decode(const char* json_string);

/**
 * Returns a string containing the JSON representation of the supplied JSON object.
 *
 * @param struct json* object
 *   The JSON object being encoded.
 *
 * @return char*
 *   The string pointer containing the JSON representation, otherwise NULL.
 */
char* json_encode(struct json* object);

/*
 * Create a new JSON object instance.
 *
 * @param enum JSONDataType type
 *   The Supported JSON Data Type.
 * @param void* value
 *   The pointer value.
 *
 * @return struct json*
 *   The pointer to the json instance, otherwise NULL.
 */
struct json* json_create(enum JSONDataType type, void* value);

/**
 * Free the memory associted to a JSON object.
 *
 * @param struct json* object
 *   The JSON object to be clean.
 */
void json_destroy(struct json* object);

#endif