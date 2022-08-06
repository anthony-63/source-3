#pragma once
#include "agt_log_stack.h"
// this *should* just be a stack of a AGT_Log struct
// but it devolved into a memory leaky mess, good luck ;)
void agt_setup_logger(unsigned capacity);
void agt_add_log(LOG_TYPE type, const char* fmt, ...);
void agt_pop_log();
