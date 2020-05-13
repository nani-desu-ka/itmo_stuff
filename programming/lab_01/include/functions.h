#pragma once

struct complex {
    double a = 1;
    double b = 2;
};

struct circle {
    double radius = 0;
    int position_x = 2;
    int position_y = 0;
};

void print (const complex &);

void multiplier (complex *, const complex *);

void multiplier (complex &, const complex &);

void print(const circle &);

void transport (circle *, const int *, const int *);

void transport (circle &, const int &, const int &);

void custom_round (double, const int &);

void custom_round (double &, const int &);

void custom_swap (int &, int &);

void custom_swap (int *, int *);

void custom_increase (int &, int);

void custom_increase (int *, int);

void custom_biggest_increase (int &, int &);

void custom_biggest_increase (int *, int *);

void custom_int_part (double &);

void custom_int_part (double *);

void custom_fractional_part (double &);

void custom_fractional_part (double *);

void custom_inverse (double &);

void custom_inverse (double *);

void custom_inverse (int &);

void custom_inverse (int *);

void custom_reverse (double &);

void custom_reverse (double *);
