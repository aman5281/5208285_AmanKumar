#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    s->arr[++s->top] = val;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

int peek(Stack *s) {
    return s->arr[s->top];
}

Stack s1, s2;

void enqueue(int val) {
    push(&s1, val);
}

void transfer() {
    if (isEmpty(&s2)) {
        while (!isEmpty(&s1)) {
            push(&s2, pop(&s1));
        }
    }
}

void dequeue() {
    transfer();
    if (!isEmpty(&s2)) {
        pop(&s2);
    }
}

void printFront() {
    transfer();
    if (!isEmpty(&s2)) {
        printf("%d\n", peek(&s2));
    }
}

int main() {
    int q;
    scanf("%d", &q);

    init(&s1);
    init(&s2);

    while (q--) {
        int type, x;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &x);
            enqueue(x);
        } else if (type == 2) {
            dequeue();
        } else if (type == 3) {
            printFront();
        }
    }
    return 0;
}
