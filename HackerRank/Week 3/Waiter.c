#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int get_prime(int idx) {
    int count = 0, num = 2;
    while (1) {
        bool is_prime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            count++;
            if (count == idx) return num;
        }
        num++;
    }
}

int* waiter(int number_count, int* number, int q, int* result_count) {
    int* answers = malloc(number_count * sizeof(int));
    int ans_idx = 0;

    int* A = malloc(number_count * sizeof(int));
    int a_top = 0;

    for (int i = 0; i < number_count; i++) {
        A[a_top++] = number[i];
    }

    for (int i = 1; i <= q; i++) {
        int prime = get_prime(i);
        int* next_A = malloc(number_count * sizeof(int));
        int na_top = 0;
        int* B = malloc(number_count * sizeof(int));
        int b_top = 0;

        for (int j = a_top - 1; j >= 0; j--) {
            if (A[j] % prime == 0) {
                B[b_top++] = A[j];
            } else {
                next_A[na_top++] = A[j];
            }
        }

        for (int j = b_top - 1; j >= 0; j--) {
            answers[ans_idx++] = B[j];
        }

        free(A);
        free(B);
        A = next_A;
        a_top = na_top;
    }

    for (int j = a_top - 1; j >= 0; j--) {
        answers[ans_idx++] = A[j];
    }

    free(A);

    *result_count = ans_idx;
    return answers;
}
