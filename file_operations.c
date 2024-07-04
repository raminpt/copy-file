#include "file_operations.h"
#include "log_messages.h"

void show_help() {
    log_message(LOG_ERR, "Usage: ./file_copy <source file path> <destination folder path>\n");
}

char *concat_path_filename(const char *path, const char *filename) {
    size_t filename_size = strlen(filename);
    size_t dst_path_size = strlen(path);

    char *dst_full_path = malloc((filename_size + dst_path_size + 1 + 1) * sizeof (char));
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

int copy_file(const char *src_file, const char *dst_file) {
    unsigned long write_count = 0;
    FILE *sf = fopen(src_file, "rb");
    FILE *df = fopen(dst_file, "wb");

    // calculate source file size
    fseek(sf, 0, SEEK_END);
    size_t sf_size = ftell(sf);
    log_message(LOG_INFO, "source file size: %lu\n", sf_size);
    // printf("source file size: %lu\n", sf_size);

    // allocate buffer equal to source file size
    char *buffer = (char *) malloc(sf_size * sizeof(char));
    rewind(sf);

    fread(buffer, 1, sf_size, sf);
    write_count = fwrite(buffer, 1, sf_size, df);

    fclose(sf);
    fclose(df);
    free(buffer);

    if(write_count == sf_size)
        return SUCCESS;
    return ERROR;
}
