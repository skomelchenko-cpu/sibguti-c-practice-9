#ifndef MATRIXFUNC_H
#define MATRIXFUNC_H

#include <stddef.h>

int read_int(int *value);
int read_pair(int *a, int *b);
void clear_line(void);
int fill_matrix(int *matptr, size_t rows, size_t cols);
void print_matrix(int *matptr, size_t rows, size_t cols);
int matrix_min(int *matptr, size_t rows, size_t cols);
size_t count_range(int *matptr, size_t rows, size_t cols, int k, int m);
long long sum_rows(int *matptr, size_t rows, size_t cols, size_t k, size_t m);

#endif
