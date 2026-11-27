#include <stdio.h>
#include "matrixfunc.h"

#define SIZE 10

int main(void) {
    int mat[SIZE * SIZE];
    size_t rows = 0, cols = 0;
    int ready = 0;
    int k, m, status;
    char choice[32];

    while (1) {
        printf("\na - Set matrix size\n"
               "b - Fill matrix\n"
               "c - Print matrix and addresses\n"
               "d - Find minimum\n"
               "e - Count elements in range\n"
               "f - Sum rows in range\n"
               "g - Exit\n"
               "Choose: ");

        if (scanf("%31s", choice) != 1)
            break;

        if (choice[1] != '\0') {
            printf("Invalid option.\n");
            clear_line();
            continue;
        }

        if (*choice == 'g')
            break;

        if (*choice >= 'c' && *choice <= 'f' && !ready) {
            printf("Fill the matrix first.\n");
            continue;
        }

        status = 1;
        switch (*choice) {
            case 'a':
                printf("Enter rows and columns (1-%d): ", SIZE);
                status = read_pair(&k, &m);
                if (status == 1) {
                    if (k < 1 || k > SIZE || m < 1 || m > SIZE) {
                        printf("Invalid size.\n");
                    } else {
                        rows = (size_t)k;
                        cols = (size_t)m;
                        ready = 0;
                    }
                }
                break;

            case 'b':
                if (rows == 0) {
                    printf("Set the size first.\n");
                    break;
                }
                printf("Enter %zu integers: ", rows * cols);
                status = fill_matrix(mat, rows, cols);
                ready = (status == 1);
                break;

            case 'c':
                print_matrix(mat, rows, cols);
                break;

            case 'd':
                printf("Minimum: %d\n", matrix_min(mat, rows, cols));
                break;

            case 'e':
                printf("Enter k and m (values): ");
                status = read_pair(&k, &m);
                if (status == 1) {
                    if (k > m)
                        printf("Invalid range.\n");
                    else
                        printf("Count: %zu\n", count_range(mat, rows, cols, k, m));
                }
                break;

            case 'f':
                printf("Enter k and m (row indices 0-%zu): ", rows - 1);
                status = read_pair(&k, &m);
                if (status == 1) {
                    if (k < 0 || m < k || (size_t)m >= rows)
                        printf("Invalid range.\n");
                    else
                        printf("Sum: %lld\n", sum_rows(mat, rows, cols, (size_t)k, (size_t)m));
                }
                break;

            default:
                printf("Invalid option.\n");
                clear_line();
        }

        if (status == EOF)
            break;
        if (status == 0) {
            printf("Invalid input.\n");
            clear_line();
        }
    }
    return 0;
}
