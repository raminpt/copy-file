#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdbool.h>

typedef enum {
    SUCCESS,
    ERROR
} STATE;

typedef struct {
    bool isFile;
    bool fileExists;
} FILE_ATTRIBUTES;

#endif //DEFINITIONS_H
