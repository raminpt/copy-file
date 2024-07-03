#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H

#include <libgen.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#include "definitions.h"

char *concat_path_filename(char *path, char *filename);

int check_file_exist(const char *filename);

int is_file(const char *filename);

int is_dir(const char *path);

int copy_file(const char *src_file, char *dst_file);

#endif //FILE_OPERATION_H
