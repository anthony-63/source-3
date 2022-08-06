#include "agt_gvars.h"
#include <stdlib.h>


AGT_gvars* agt_setup_gvars() {
    AGT_gvars *gvars = (AGT_gvars*)malloc(sizeof(AGT_gvars*));
    gvars->g_var_num_data[0] = 0x000000;
    gvars->g_var_key[0] = (char*)malloc(sizeof(char) * 128);
    gvars->g_var_key[0] = "bg.color";
}

int agt_gvar_access(AGT_gvars* gvars, char* key) {
    for(int i = 0; i < GVAR_COUNT; i++) {
        if(strcmp(gvars->g_var_key[i], key) == 0) {
            return gvars->g_var_num_data[i];
        }
    }
}
void agt_gvar_set(AGT_gvars* gvars, char* key, int value) {
    for(int i = 0; i < GVAR_COUNT; i++) {
        if(strcmp(gvars->g_var_key[i], key) == 0) {
            gvars->g_var_num_data[i] = value;
            return;
        }
    }
}