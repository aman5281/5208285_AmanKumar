#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

// Min-heap implementation in C for Jesse and Cookies

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify_up(int *heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] <= heap[idx]) break;
        swap(&heap[parent], &heap[idx]);
        idx = parent;
    }
}

void heapify_down(int *heap, int size, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest == idx) break;

        swap(&heap[idx], &heap[smallest]);
        idx = smallest;
    }
}

int extract_min(int *heap, int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify_down(heap, *size, 0);
    return root;
}

void insert_heap(int *heap, int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapify_up(heap, *size - 1);
}

int cookies(int k, int A_count, int* A) {
    // Build initial heap
    for (int i = (A_count / 2) - 1; i >= 0; i--) {
        heapify_down(A, A_count, i);
    }

    int size = A_count;
    int operations = 0;

    while (size > 1 && A[0] < k) {
        int least = extract_min(A, &size);
        int second = extract_min(A, &size);

        long long new_cookie = (long long)least + 2LL * second;

        insert_heap(A, &size, (int)new_cookie);
        operations++;
    }

    if (A[0] >= k) return operations;
    return -1;
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char** A_temp = split_string(rtrim(readline()));

    int* A = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int A_item = parse_int(*(A_temp + i));

        *(A + i) = A_item;
    }

    int result = cookies(k, n, A);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
