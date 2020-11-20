#include "header.h"
//@date 2020-11-20
typedef struct stack{
    int *arr;
    int index;
}Stack;

Stack * stack_init(int stack_size){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (int *)malloc(sizeof(int) * stack_size);
    stack->index = 0;
    return stack;
}

void push(Stack stack,int val){
    stack.arr[stack.index] = val;
    stack.index = stack.index + 1;
}

int pop(Stack stack){
    int ret = stack.arr[stack.index];
    stack.index = stack.index - 1;
    return ret;
}

int top(Stack stack){
    return stack.arr[stack.index];
}

int stack_size(Stack stack){
    return stack.index;
}