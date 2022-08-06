#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef enum {
    AGT_LOG_WARNING,
    AGT_LOG_ERROR,
    AGT_LOG_INFO,
    AGT_LOG_DEBUG
} LOG_TYPE;

typedef struct AGT_Log AGT_Log;
typedef struct AGT_Log {
    char* info;
    LOG_TYPE type;
} AGT_Log; 

typedef struct AGT_log_stack AGT_log_stack;
typedef struct AGT_log_stack {
    int top;
    unsigned capacity;
    AGT_Log** arr;
} AGT_log_stack;
// what a long function name
AGT_log_stack* agt_construct_log_stack(unsigned capacity);
void     agt_log_stack_push(AGT_log_stack* stack, AGT_Log* item);
AGT_Log* agt_log_stack_pop (AGT_log_stack* stack);
AGT_Log* agt_log_peek      (AGT_log_stack* stack);