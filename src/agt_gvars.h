#pragma once

#include <string.h>

#define GVAR_COUNT 1
typedef struct AGT_gvars AGT_gvars;
    
typedef struct AGT_gvars {
    int g_var_num_data[GVAR_COUNT];
    char *g_var_key[GVAR_COUNT];
}AGT_gvars;

AGT_gvars* agt_setup_gvars();

int agt_gvar_access(AGT_gvars* gvars, char* key);

void agt_gvar_set(AGT_gvars* gvars, char* key, int value);