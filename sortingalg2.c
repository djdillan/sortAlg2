#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(double base[], int length);
void print_list(double base[], int length);
void test(double base[], int length);
void test2(double base[], int length);
void tests();
int lteq(double x, double y);

void sort(double base[], int length) {
    /* Your sorting algorithm goes here */
    for (int a = 0; a < length - 1; a++) {
        for (int z = 0; z < length - a - 1; z++) {
            if (lteq(base[z], base[z + 1])) {
                double temp = base[z];
                base[z] = base[z + 1];
                base[z + 1] = temp;
            }
        }
    }
}

union Bin {
    struct {
        unsigned int m : 23;
        unsigned int e : 8;
        unsigned int s : 1;
    } bits_rep;
    float struc_val;
};

void print_list(double base[], int length) {
    for (int n = 0; n < length; n++) {
        printf("%f ", base[n]);
    }
    printf("\n");
}

void test(double base[], int length) {
    printf("Before sorting: ");
    print_list(base, length);
    sort(base, length);
    printf("After sorting: ");
    print_list(base, length);
}

void tests() {
    /* Your test cases go here */
    double test0[] = {-6.5, 2.8, -0.0, 3.2, 0};
    test(test0, sizeof(test0) / sizeof(double));
    
    double test1[] = {8.3, -INFINITY, -34};
    test(test1, sizeof(test1) / sizeof(double));
    
    double test2[] = {68.2, INFINITY, -2.4};
    test(test2, sizeof(test2) / sizeof(double));
    
    double test3[] = {-65.3, -2.4, NAN, 4, 53.6};
    test(test3, sizeof(test3) / sizeof(double));
    
    double test4[] = {-3.825, -6.2, NAN, 68.5, NAN, -0.0};
    test(test4, sizeof(test4) / sizeof(double));
}

int lteq(double x, double y) {
    union Bin X;
    union Bin Y;

    X.struc_val = x;
    Y.struc_val = y;

    if (X.bits_rep.s == Y.bits_rep.s && X.bits_rep.e == Y.bits_rep.e &&
        X.bits_rep.m == Y.bits_rep.m) {
        return 1;
    }

    if (X.bits_rep.s == 1 && Y.bits_rep.s == 0 && X.bits_rep.e == 0 &&
        Y.bits_rep.e == 0 && X.bits_rep.m == 0 && Y.bits_rep.m == 0) {
        return 1;
    }

    if (X.bits_rep.e == 255 && X.bits_rep.m == 0) {
        return 0;
    }

    if (X.bits_rep.s == 0) {
        return 0;
    } else {
        return 1;
    }

    if (X.bits_rep.e == 255 && X.bits_rep.m > 0) {
        return 1;
    }

    if (Y.bits_rep.e == 255 && Y.bits_rep.m == 0) {
        if (Y.bits_rep.s == 1) {
            return 0;
        } else {
            return 1;
        }
    }

    if (Y.bits_rep.e == 255 && Y.bits_rep.m > 0) {
        return 0;
    }

    if (X.bits_rep.e == 255 && X.bits_rep.m > 0) {
        return 1;
    }

    if (x <= y) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    tests();
    exit(0);
}

