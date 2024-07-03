#include "file_operations.h"

char *concat_path_filename(char *path, char *filename) {
    size_t filename_size = strlen(filename);
    size_t dst_path_size = strlen(path);

    char *dst_full_path = (char *) malloc((filename_size + dst_path_size + 1 + 1) * sizeof (char));
    strcat(dst_full_path, path);
    strcat(dst_full_path, "/");
    strcat(dst_full_path, filename);

    return dst_full_path;
}

int check_file_exist(const char *filename) {
    FILE *f = fopen(filename, "r");
    if(f != NULL) {
        fclose(f);
        return SUCCESS;
    }
    return ERROR;
}

int is_file(const char *filename) {
    struct stat s;
    if(lstat(filename, &s) == 0)
        if((s.st_mode & S_IFMT) == S_IFREG)
            return SUCCESS;
    return ERROR;
}

int is_dir(const char *path) {
    struct stat s;
    if(lstat(path, &s) == 0)
        if((s.st_mode & S_IFMT) == S_IFDIR)
            return SUCCESS;
    return ERROR;
}

int copy_file(const char *src_file, char *dst_file) {
    FILE *sf = fopen(src_file, "rb");
    FILE *df = fopen(dst_file, "wb");

    fseek(sf, 0, SEEK_END);
    size_t sf_size = ftell(sf);
    printf("source file size: %lu\n", sf_size);

    char *buffer = (char *) malloc(sf_size * sizeof(char));
    rewind(sf);
    fread(buffer, 1, sf_size, sf);

    fwrite(buffer, 1, sf_size, df);

    fclose(sf);
    fclose(df);
    free(buffer);

    return SUCCESS;
}
