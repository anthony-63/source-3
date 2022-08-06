#include "agt_logging.h"
#include <stdarg.h>
AGT_log_stack* _g_log_stack;
void agt_setup_logger(unsigned capacity) {
    _g_log_stack = agt_construct_log_stack(capacity);
}
void agt_add_log(LOG_TYPE type, const char* fmt, ...) {
    AGT_Log* log = (AGT_Log*)malloc(sizeof(AGT_Log*));
    log->type = type;
    char _log[4086];
    va_list args;
    va_start(args, fmt);
    vsprintf(_log, fmt, args);
    log->info = _log;
    va_end(args);
    agt_log_stack_push(_g_log_stack, log);
}
void agt_pop_log(){

}