// #ifndef JSON_FORMATTER_HPP
// #define JSON_FORMATTER_HPP

// #include <ArduinoJson.h>

// #define FULL_JSON_SIZE 2048

// class JsonFormatter
// {
// public:
//     virtual void appendJson(StaticJsonDocument<FULL_JSON_SIZE> &document) = 0;

//     String getStringFromJson()
//     {
//         String result;
//         StaticJsonDocument<FULL_JSON_SIZE> document;
//         this->appendJson(document);
//         serializeJsonPretty(document, result);
//         return result;
//     }
// };

// #endif // JSON_FORMATTER_HPP