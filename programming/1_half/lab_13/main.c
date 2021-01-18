#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void make_copy(FILE *file_src, FILE *file_copy) {
    fseek(file_src, 0, 0);
    fseek(file_copy, 0, 0);
    int element;
    element = getc(file_src);
    while (element != EOF) {
        putc(element, file_copy);
        element = getc(file_src);
    }
    fclose(file_src);
    fclose(file_copy);
}

unsigned int inverter(unsigned int size[8]) {
    unsigned int output = 0;
    int power = 1;
    for (int i = 0; i < 8; i++) {
        output += size[7 - i] * power;
        power *= 2;
    }
    return output;
}

unsigned int bit_to_int(unsigned char size[4]) {
    unsigned int temp_int = 0;
    temp_int = temp_int | ((unsigned int)size[0] << 23);
    temp_int = temp_int | ((unsigned int)size[1] << 15);
    temp_int = temp_int | ((unsigned int)size[2] << 7);
    temp_int = temp_int | (unsigned int)size[3];
    return temp_int;
}

void int_to_bit(unsigned int size, unsigned char out[4]) {
    int a;
    int i = 0;
    int j = 3;
    unsigned int b[4][8] = {{0}, {0}, {0}, {0}};
    while (size >= 1) {
        if (i == 8) {
            j--;
            i = 0;
        }
        if (i == 7) {
            i++;
        }
        a = size % 2;
        b[j][7 - i] = a;
        i++;
        size = size / 2;
    }
    for (int x = 0; x < 4; x++) {
        out[x] = inverter(b[x]);
    }
}

typedef union {
    unsigned char bytes[10];
    struct {
        unsigned char id3[3];
        unsigned char version;
        unsigned char subversion;
        unsigned char flag;
        unsigned char size[4];
    } body;
} HEADER;

typedef union {
    unsigned char bytes[10];
    struct {
        unsigned char name[4];
        unsigned char size[4];
        unsigned char flags[2];
    } body;
} FRAME;

void print_field(FRAME frame, FILE *File) {
    unsigned char *content = malloc(bit_to_int(frame.body.size));
    fread(content, 1, bit_to_int(frame.body.size), File);
    content[0] = ' ';
    printf("%s:", frame.body.name);
    printf("%s", content);
    printf("\n");
    free(content);
}

void show(FILE *File) {
    fseek(File, 0, 0);
    HEADER header;
    fread(header.bytes, 1, 10, File);
    printf("%s\n", header.body.id3);
    printf("VERSION: %u\n", (unsigned int)header.body.version);
    printf("SUBVERSION: %u\n", (unsigned int)header.body.subversion);
    printf("SIZE: %u\n", bit_to_int(header.body.size));
    while (ftell(File) < bit_to_int(header.body.size)) {
        FRAME frame;
        fread(frame.bytes, 1, 10, File);
        if (frame.body.name[0] == 0) {
            break;
        }
        print_field(frame, File);
    }
}

void get(char *value, FILE *File) {
    fseek(File, 0, 0);
    HEADER header;
    fread(header.bytes, 1, 10, File);
    while (ftell(File) < bit_to_int(header.body.size)) {
        FRAME frame;
        fread(frame.bytes, 1, 10, File);
        if (strcmp(value, frame.body.name) == 0) {
            print_field(frame, File);
        } else {
            unsigned char *content = malloc(bit_to_int(frame.body.size));
            fread(content, 1, bit_to_int(frame.body.size), File);
            free(content);
        }
    }
}
void set(char *field, char *value, char *file_path, FILE *File) {
    FILE *buffer_file = fopen("buffer", "wb");
    make_copy(File, buffer_file);
    buffer_file = fopen("buffer", "rb");

    fseek(buffer_file, 0, 0);
    HEADER header;
    fread(header.bytes, 1, 10, buffer_file);
    unsigned int header_size = bit_to_int(header.body.size);
    unsigned int prev_position = 0;
    unsigned int prev_size = 0;
    while (ftell(buffer_file) < bit_to_int(header.body.size)) {
        FRAME frame;
        fread(frame.bytes, 1, 10, buffer_file);
        unsigned int frame_size = bit_to_int(frame.body.size);
        if (strcmp(frame.body.name, field) == 0) {
            prev_position = (unsigned int)ftell(buffer_file) - 10;
            prev_size = frame_size;
            break;
        }
        fseek(buffer_file, frame_size, 1); // возвращаем текущее положение курсора, сдивнутое на фреймсайз
    }
    unsigned int new_size = (unsigned int)strlen(value) + 1;
    unsigned int new_header_size = header_size - prev_size + new_size ;
    fclose(buffer_file);
    buffer_file = fopen("buffer", "rb");
    File = fopen(file_path, "wb");
    unsigned char new_char_size[4];
    int_to_bit(new_header_size, new_char_size);
    header.body.size[0] = new_char_size[0];
    header.body.size[1] = new_char_size[1];
    header.body.size[2] = new_char_size[2];
    header.body.size[3] = new_char_size[3];
    fwrite(header.bytes, sizeof(char), 10, File); // записываем поэлементно 10 символов в буфер, начиная со 2
    fseek(buffer_file, 10, 0); // переходим на 10 символов вперед в новом файле
    if (prev_position == 0 || strlen(value) == 0) {
        printf("Unknown field or blank value\n");
        return;
    }
    for (int i = 0; i < prev_position - 10; ++i) { // посимвольно читаем
        int element = getc(buffer_file); // присваиваем символ
        putc(element, File); // суем символ
    }
    if (new_size > 0) {
        FRAME frame;
        for (int i = 0; i < 4; ++i)
            frame.body.name[i] = field[i];
        unsigned char helper[4];
        int_to_bit(new_size, helper);
        frame.body.size[0] = helper[0];
        frame.body.size[1] = helper[1];
        frame.body.size[2] = helper[2];
        frame.body.size[3] = helper[3];
        frame.body.flags[0] = 0;
        frame.body.flags[1] = 0;
        fwrite(frame.bytes, sizeof(char), 10, File);
    }
    unsigned char helper[4];
    int_to_bit(0, helper);
    fwrite(helper, 1, 1, File);
    fwrite(value, 1, new_size - 1, File);
    fseek(buffer_file, prev_position + 10 + prev_size, 0);
    for (int i = prev_position; i < new_header_size; i++) {
        int element = getc(buffer_file);
        putc(element, File);
    }
    int element = getc(buffer_file);
    while (element != EOF) {
        putc(element, File);
        element = getc(buffer_file);
    }
    printf("SUCCESS\n");
    fclose(buffer_file);
    remove("buffer");
}

int main(int argc, char **argv) {
    FILE *inputFile;
    int show_option = 0;
    char *set_field = NULL;
    char *set_value = NULL;
    char *get_value = NULL;
    char *name;
    for (int i = 1; i < argc; i++) {
        char *parsed_string = strtok(argv[i], "=");
        if (strcmp(parsed_string, "--show") == 0) {
            show_option = 1;
        } else if (strcmp(parsed_string, "--get") == 0) {
            get_value = strtok(NULL, "=");
        } else if (strcmp(parsed_string, "--set") == 0) {
            set_field = strtok(NULL, "=");
        } else if (strcmp(parsed_string, "--value") == 0) {
            set_value = strtok(NULL, "=");
        } else if (strcmp(parsed_string, "--filepath") == 0) {
            name = strtok(NULL, "=");
            inputFile = fopen(name, "rb");
        } else {
            printf("Invalid argument: %s", argv[i]);
            return 0;
        }
    }

    if (inputFile == NULL) {
        printf("File does not exist");
        return 0;
    }

    if (show_option && (get_value != NULL || set_field != NULL || set_value != NULL)) {
        printf("Too many arguments given");
        return 0;
    } else if (get_value && (set_field != NULL || set_value != NULL)) {
        printf("Too many arguments given");
        return 0;
    }

    if (show_option != 0) {
        show(inputFile);
    } else if (get_value != NULL) {
        get(get_value, inputFile);
    } else if (set_value != NULL && set_field != NULL) {
        set(set_field, set_value, name, inputFile);
    } else {
        printf("No arguments given");
    }
    fclose(inputFile);
    return 0;
}