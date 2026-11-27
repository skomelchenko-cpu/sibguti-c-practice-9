#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include "matrixfunc.h"

int read_int(int *value) {
    char text[32], *end;
    long x;

    if (scanf("%31s", text) != 1)
        return EOF;

    errno = 0;
    x = strtol(text, &end, 10);
    if (strlen(text) == 31 || *end != '\0' || errno == ERANGE ||
        x < INT_MIN || x > INT_MAX)
        return 0;

    *value = (int)x;
    return 1;
}

int read_pair(int *a, int *b) {
    int status = read_int(a);
    if (status != 1)
        return status;
    return read_int(b);
}

void clear_line(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int fill_matrix(int *matptr, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            int status = read_int(matptr + i * cols + j);
            if (status != 1)
                return status;
        }
    }
    return 1;
}

void print_matrix(int *matptr, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            int *p = matptr + i * cols + j;
            printf("(%zu, %zu): %d  %p\n", i, j, *p, (void *)p);
        }
    }
}

int matrix_min(int *matptr, size_t rows, size_t cols) {
    int min = *matptr;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (*(matptr + i * cols + j) < min)
                min = *(matptr + i * cols + j);
        }
    }
    return min;
}

size_t count_range(int *matptr, size_t rows, size_t cols, int k, int m) {
    size_t count = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            int x = *(matptr + i * cols + j);
            if (x >= k && x <= m)
                count++;
        }
    }
    return count;
}

long long sum_rows(int *matptr, size_t rows, size_t cols, size_t k, size_t m) {
    long long sum = 0;
    for (size_t i = k; i < rows && i <= m; i++) {
        for (size_t j = 0; j < cols; j++)
            sum += *(matptr + i * cols + j);
    }
    return sum;
}
