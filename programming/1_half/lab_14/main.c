#include <stdio.h>
#include "bmp_library.h"
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <limits.h>


bmp_pixel ***matrix_storage;
int win = -1;

void delay(float number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

int bmp_equal(bmp_pixel first, bmp_pixel second) {
    if (abs((int)first.red - (int)second.red) < 100 || abs((int)first.green - (int)second.green) < 100 || abs((int)first.blue - (int)second.blue) < 100) {
        return 1;
    } else {
        return 0;
    }
}

int square_checker(bmp_img *image, int x, int y) {
    int height = image->img_header.biHeight;
    int width = image->img_header.biWidth;
    int counter = 0;
    if (bmp_equal(image->img_pixels[(y + 1) % height][x], BMP_PIXEL(0, 0, 0)) == 1) counter++;
    if (bmp_equal(image->img_pixels[(height + y - 1) % height][x], BMP_PIXEL(0, 0, 0)) == 1) counter++;
    if (bmp_equal(image->img_pixels[(y + 1) % height][(x + 1) % width], BMP_PIXEL(0, 0, 0)) == 1) counter++;
    if (bmp_equal(image->img_pixels[y][(x + 1) % width], BMP_PIXEL(0, 0, 0)) == 1) counter++;
    if (bmp_equal(image->img_pixels[(height + y - 1) % height][(x + 1) % width], BMP_PIXEL(0, 0, 0)) == 1) counter++;
    if (bmp_equal(image->img_pixels[y][(width + x - 1) % width], BMP_PIXEL(0, 0, 0)) == 1) counter++;
    if (bmp_equal(image->img_pixels[(y + 1) % height][(width + x - 1) % width], BMP_PIXEL(0, 0, 0)) == 1) counter++;
    if (bmp_equal(image->img_pixels[(height + y - 1) % height][(width + x - 1) % width], BMP_PIXEL(0, 0, 0)) == 1) counter++;
    return counter;
}

void check_win(int step, int width, int height) {
    int blank = 1;
    int repeat = 1;
    int flag = 0;
    for (int i = 0; i < step; i++) {
        flag = 1;
        if (blank == 0 && repeat == 0) break;
        for (int j = 0; j < height; j++) {
            if (blank == 0 && repeat == 0) break;
            for (int k = 0; k < width; k++) {
                if (bmp_equal(matrix_storage[i][j][k], matrix_storage[step][j][k]) == 0) repeat = 0;
                if (bmp_equal(BMP_PIXEL(0, 0, 0), matrix_storage[step][j][k]) == 1) blank = 0;
                if (blank == 0 || repeat == 0) break;
            }
        }
    }
    if (blank == 1 && repeat == 1 && flag == 1) {
        win = step;
    }
}

int make_step(bmp_img *image, int step) {
    size_t height = abs(image->img_header.biHeight);
    size_t width = image->img_header.biWidth;
    matrix_storage[step] = (bmp_pixel **)malloc(height * sizeof(bmp_pixel *));
    for (size_t i = 0; i < height ; i++) {
        matrix_storage[step][i] = (bmp_pixel *)malloc(width * sizeof(bmp_pixel));
        for (size_t j = 0; j < width; j++) {
            int total_neighbours = square_checker(image, j, i);
            if (total_neighbours == 0) {
                matrix_storage[step][i][j] = BMP_PIXEL(255, 255, 255);
                continue;
            }
            if ((total_neighbours == 3) || ((bmp_equal(image->img_pixels[i][j], BMP_PIXEL(0, 0, 0)) == 1)
            && (total_neighbours == 2))) {
                matrix_storage[step][i][j] = BMP_PIXEL(0, 0, 0);
            } else {
                matrix_storage[step][i][j] = BMP_PIXEL(255, 255, 255);
            }
        }
    }
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            bmp_pixel_init(&image->img_pixels[i][j], matrix_storage[step][i][j].red, matrix_storage[step][i][j].green, matrix_storage[step][i][j].blue);
        }
    }
    check_win(step, width, height);
}

int main(int argc, char **argv) {
    bmp_img input_img;
    int input_name_number = 0;
    int output_name_number = 0;
    int max_iter = 0;
    int dump_freq = 0;
    int max = INT_MAX;
    int freq = 1;
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--input") == 0) {
            assert(i + 1 < argc);
            input_name_number = i + 1;
        } else if (strcmp(argv[i], "--output") == 0) {
            assert(i + 1 < argc);
            output_name_number = i + 1;
        } else if (strcmp(argv[i], "--max_iter") == 0) {
            assert(i + 1 < argc);
            max_iter = i + 1;
        } else if (strcmp(argv[i], "--dump_freq") == 0) {
            assert(i + 1 < argc);
            dump_freq = i + 1;
        }
    }
    assert(input_name_number > 0);
    assert(output_name_number > 0);
    if (max_iter != 0) {
        max = atoi(argv[max_iter]);
    }
    if (dump_freq != 0) {
        freq = atoi(argv[dump_freq]);
    }
    matrix_storage = (bmp_pixel ***)malloc(max * sizeof(bmp_pixel **));
    bmp_img_read(&input_img, argv[input_name_number]);
    for (int i = 0; i < max; i++) {
        make_step(&input_img, i);
        if (i % freq == 0) {
            char output[111] = "";
            strcat(output, argv[output_name_number]);
            strcat(output, "/");
            char number[100];
            itoa(i, number, 10);
            strcat(number, ".bmp");
            strcat(output, number);
            bmp_img_write(&input_img, output);
//            bmp_img_write(&input_img, "../output/0.bmp");
//            delay(0.1);
        }
        if (win != -1) {
            printf("WIN\n");
            break;
        }
    }
    for (int i = 0; i <= win; i++) {
        for (int j = 0; j < input_img.img_header.biHeight; j++) {
            free(matrix_storage[i][j]);
        }
        free(matrix_storage[i]);
    }
    free(matrix_storage);
    bmp_img_free(&input_img);
    return 0;
}