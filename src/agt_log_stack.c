#include "agt_log_stack.h"

AGT_log_stack* agt_construct_log_stack(unsigned capacity) { 
    struct AGT_log_stack* stack =(struct AGT_log_stack*)malloc(sizeof(AGT_log_stack));
    stack->capacity = capacity;
    stack->top = -1;
    // this is a terrible way to implement a logging system
    // if there are more logs than the capacity it will delete all of them automatically
    stack->arr = (AGT_Log**)malloc(stack->capacity * sizeof(AGT_Log*));
    return stack;
}

int is_full(AGT_log_stack* stack) {
    return stack->top == stack->capacity - 1;
}

int is_empty(AGT_log_stack* stack) {
    return stack->top == -1;
}

void agt_log_stack_push(AGT_log_stack* stack, AGT_Log* item) {
    if(is_full(stack)) return;
    stack->arr[++stack->top] = item;
}

AGT_Log* agt_log_stack_pop(AGT_log_stack* stack) {
    if(is_empty(stack)) return (AGT_Log*)INT_MIN;
    return stack->arr[stack->top--];
}

AGT_Log* agt_log_stack_peek(AGT_log_stack* stack){
    if(is_empty(stack)) return (AGT_Log*)INT_MIN;
    return stack->arr[stack->top];
}
