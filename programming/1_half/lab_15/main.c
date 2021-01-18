#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int file_writer(FILE* archive, char* archive_name) {
    FILE* read_file = fopen(archive_name, "rb");
    if (read_file == NULL) {
        printf("Extension error");
        return 1;
    }

    for (int i = 0; i < strlen(archive_name); ++i) {
        fwrite(archive_name + i, 1, 1, archive);
    }

    char begin_symbol = 0;
    char end_symbol = 1;
    fwrite(&begin_symbol, 1, 1, archive);

    char buffer;
    while (fread(&buffer, 1, 1, read_file) != 0) {
        fwrite(&buffer, 1, 1, archive);
    }
    fwrite(&end_symbol, 1, 1, archive);
    fclose(read_file);
    return 0;
}

void extract_archive(char* name_of_archive){
    FILE* archive = fopen(name_of_archive, "rb");
    char* buffer = calloc(17, 1);
    fread(buffer, 1, 17, archive);
    if (strncmp(buffer, "CUSTOM_ARCHIVE_NK", 17) != 0) {
        printf("This is not archive\n");
        return;
    }
    free(buffer);

    int files_amount = 0;
    fread(&files_amount, sizeof(int), 1, archive);
    int k;
    char *buffer_name;
    unsigned char buffer_byte;
    for (int i = 0; i < files_amount; ++i) {
        FILE* writing_file;
        k = 1;
        buffer_name = calloc(1, 1);
        *buffer_name = '\0';
        buffer_byte = 0;
        fread(&buffer_byte, 1, 1, archive);
        while (buffer_byte != 0) {
            buffer_name = (char *)realloc(buffer_name, k);
            buffer_name[k - 1] = buffer_byte;
            fread(&buffer_byte, 1, 1, archive);
            k++;
        }
        buffer_name = (char *)realloc(buffer_name, k);
        buffer_name[k - 1] = '\0';
        writing_file = fopen(buffer_name, "wb");
        free(buffer_name);
        fread(&buffer_byte, 1, 1, archive);
        while (buffer_byte != 1) {
            fwrite(&buffer_byte, 1, 1, writing_file);
            fread(&buffer_byte, 1, 1, archive);

    }    fclose(writing_file);
    }
    fclose(archive);
}

void list_files(char* name_of_archive){
    FILE* archive = fopen(name_of_archive, "rb");
    char* buffer = calloc(17, 1);
    fread(buffer, 1, 17, archive);
    if (strncmp(buffer, "CUSTOM_ARCHIVE_NK", 17) != 0) {
        printf("This is not archive\n");
        return;
    }
    free(buffer);
    printf("List of files:\n");

    int files_amount = 0;
    fread(&files_amount, sizeof(int), 1, archive);
    int k;
    char *buffer_name;
    unsigned char buffer_byte;

    printf("Amount of files: %d\n", files_amount);
    for (int i = 0; i < files_amount; i++) {
        k = 1;
        buffer_name = calloc(1, 1);
        *buffer_name = '\0';
        buffer_byte = 0;
        fread(&buffer_byte, 1, 1, archive);
        while (buffer_byte != 0) {
            buffer_name = (char *)realloc(buffer_name, k);
            buffer_name[k - 1] = buffer_byte;
            fread(&buffer_byte, 1, 1, archive);
            k++;
        }
        buffer_name = (char *)realloc(buffer_name, k);
        buffer_name[k - 1] = '\0';
        printf("%s\n", buffer_name);
        free(buffer_name);
        while (buffer_byte != 1) {
            fread(&buffer_byte, 1, 1, archive);
        }
    }
    fclose(archive);
}

int main(int argc, char **argv) {
    unsigned char archive_flag = 0;
    char *archive_name = "";
    int index_of_first_file = 0;
    int create_flag = 0;
    int extract_flag = 0;
    int list_flag = 0;

    for (int i = 1; i < argc; i++) {
        if (create_flag) {
            if (strlen(argv[i]) >= 2 && strncmp(argv[i], "--", 2) == 0) {
                printf("Key error\n");
                return 0;
            }
            continue;
        }
        if (strlen(argv[i]) > 2 && strncmp(argv[i], "--", 2) == 0) {
            if (strlen(argv[i]) == 6 && strncmp(argv[i], "--file", 6) == 0) {
                archive_flag = 1;
                archive_name = argv[i + 1];
            } else if (strlen(argv[i]) == 8 && strncmp(argv[i], "--create", 8) == 0) {
                create_flag = 1;
                index_of_first_file = i + 1;
            } else if (strlen(argv[i]) == 9 && strncmp(argv[i], "--extract", 9) == 0) {
                extract_flag = 1;
            } else if (strlen(argv[i]) == 6 && strncmp(argv[i], "--list", 6) == 0) {
                list_flag = 1;
            } else {
                printf("Invalid argument\n");
                return 1;
            }
        }
    }

    if (!archive_flag) {
        printf("Error: --file was not found\n");
        return 1;
    }
    if (create_flag + extract_flag + list_flag != 1) {
        printf("Wrong amount of keys\n");
        return 1;
    }

    if (create_flag) {
        int files_amount = argc - index_of_first_file;
        FILE* archive = fopen(archive_name, "wb");
        fwrite("CUSTOM_ARCHIVE_NK", 1, 17, archive);
        fwrite(&files_amount, sizeof(int), 1, archive);
        for (int i = index_of_first_file; i < argc; ++i) {
            file_writer(archive, argv[i]);
        }
        fclose(archive);
    } else if (list_flag) {
        list_files(archive_name);
    } else if (extract_flag) {
        extract_archive(archive_name);
    }
    return 0;
}