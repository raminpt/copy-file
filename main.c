#include <stdio.h>

#include "file_operations.h"

int main(int argc, char *argv[]) {
    char user_response;
    FILE_ATTRIBUTES fa = {false, false};

    char *filename = basename(argv[1]);
    char *dst_full_path = concat_path_filename(argv[2], filename);

    int result = check_file_exist(dst_full_path);
    if(result == SUCCESS) {
        fa.fileExists = true;
        printf("%s exists.\n", dst_full_path);
    }
    else
        printf("%s does not exist.\n", dst_full_path);

    result = is_file(argv[1]);
    if(result == SUCCESS) {
        fa.isFile = true;
        printf("%s is a file.\n", argv[1]);
    }
    else {
        printf("%s is a not file.\n", argv[1]);
        return ERROR;
    }

    result = is_dir(argv[2]);
    if(result == SUCCESS)
        printf("%s is a directory.\n", argv[2]);
    else {
        printf("%s is a not directory.\n", argv[2]);
        return ERROR;
    }

    if(fa.isFile && is_dir(argv[2]) == SUCCESS) {
        if(fa.fileExists) {
            printf("%s is already exist, are you sure? [Y/n]: ", argv[1]);
            scanf(" %c", &user_response);
            while (true) {
                if(user_response == 'Y')
                    break;
                else if(user_response == 'n')
                    return ERROR;
                else {
                    printf("Please 'Y' or 'n': ");
                    scanf(" %c", &user_response);
                }
            }
        }
        copy_file(argv[1], dst_full_path);
    }

    free(dst_full_path);
    return 0;
}
