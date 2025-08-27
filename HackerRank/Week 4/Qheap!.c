#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000   // Maximum heap size

int heap[MAXN+1];     // 1-indexed heap
int heap_size = 0;

// Swap utility
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Heapify-up (after insertion)
void heapify_up(int i) {
    while (i > 1 && heap[i] < heap[i/2]) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

// Heapify-down (after deletion)
void heapify_down(int i) {
    int left = 2*i, right = 2*i+1, smallest = i;
    if (left <= heap_size && heap[left] < heap[smallest]) smallest = left;
    if (right <= heap_size && heap[right] < heap[smallest]) smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(smallest);
    }
}

// Insert element
void insert(int val) {
    heap[++heap_size] = val;
    heapify_up(heap_size);
}

// Find index of element
int find(int val) {
    for (int i = 1; i <= heap_size; i++) {
        if (heap[i] == val) return i;
    }
    return -1; // should never happen as per problem statement
}

// Delete element
void delete_val(int val) {
    int idx = find(val);
    if (idx == -1) return;
    heap[idx] = heap[heap_size--]; // Replace with last
    heapify_up(idx);   // In case new value is smaller
    heapify_down(idx); // In case new value is larger
}

// Get minimum
int get_min() {
    return heap[1];
}

int main() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type, v;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &v);
            insert(v);
        } else if (type == 2) {
            scanf("%d", &v);
            delete_val(v);
        } else if (type == 3) {
            printf("%d\n", get_min());
        }
    }
    return 0;
}
