#include "agt_input.h"

int _g_show_cons = 0;
extern char *_g_cons_inp_text;
char** org_inp_addr = &_g_cons_inp_text;
int inp_loc = 0;
int _g_enter_cmd = 0;
#define INP_CHAR_MAX 140
void agt_input_handler(SDL_Event ev) {
    if(ev.type == SDL_KEYDOWN) {
        switch(ev.key.keysym.sym) {
            case SDLK_INSERT: _g_show_cons = !_g_show_cons;SDL_StartTextInput();break;
        }
        if(_g_show_cons) {
            if(inp_loc >= INP_CHAR_MAX) {
                memset(_g_cons_inp_text, 0, sizeof(char) * 4096);
                inp_loc = 0;
            }
            switch(ev.key.keysym.sym){
                case SDLK_a: _g_cons_inp_text[inp_loc++] = 'a';break;
                case SDLK_b: _g_cons_inp_text[inp_loc++] = 'b';break;
                case SDLK_c: _g_cons_inp_text[inp_loc++] = 'c';break;
                case SDLK_d: _g_cons_inp_text[inp_loc++] = 'd';break;
                case SDLK_e: _g_cons_inp_text[inp_loc++] = 'e';break;
                case SDLK_f: _g_cons_inp_text[inp_loc++] = 'f';break;
                case SDLK_g: _g_cons_inp_text[inp_loc++] = 'g';break;
                case SDLK_h: _g_cons_inp_text[inp_loc++] = 'h';break;
                case SDLK_i: _g_cons_inp_text[inp_loc++] = 'i';break;
                case SDLK_j: _g_cons_inp_text[inp_loc++] = 'j';break;
                case SDLK_k: _g_cons_inp_text[inp_loc++] = 'k';break;
                case SDLK_l: _g_cons_inp_text[inp_loc++] = 'l';break;
                case SDLK_m: _g_cons_inp_text[inp_loc++] = 'm';break;
                case SDLK_n: _g_cons_inp_text[inp_loc++] = 'n';break;
                case SDLK_o: _g_cons_inp_text[inp_loc++] = 'o';break;
                case SDLK_p: _g_cons_inp_text[inp_loc++] = 'p';break;
                case SDLK_q: _g_cons_inp_text[inp_loc++] = 'q';break;
                case SDLK_r: _g_cons_inp_text[inp_loc++] = 'r';break;
                case SDLK_s: _g_cons_inp_text[inp_loc++] = 's';break;
                case SDLK_t: _g_cons_inp_text[inp_loc++] = 't';break;
                case SDLK_u: _g_cons_inp_text[inp_loc++] = 'u';break;
                case SDLK_v: _g_cons_inp_text[inp_loc++] = 'v';break;
                case SDLK_w: _g_cons_inp_text[inp_loc++] = 'w';break;
                case SDLK_x: _g_cons_inp_text[inp_loc++] = 'x';break;
                case SDLK_y: _g_cons_inp_text[inp_loc++] = 'y';break;
                case SDLK_0: _g_cons_inp_text[inp_loc++] = '0';break;
                case SDLK_1: _g_cons_inp_text[inp_loc++] = '1';break;
                case SDLK_2: _g_cons_inp_text[inp_loc++] = '2';break;
                case SDLK_3: _g_cons_inp_text[inp_loc++] = '3';break;
                case SDLK_4: _g_cons_inp_text[inp_loc++] = '4';break;
                case SDLK_5: _g_cons_inp_text[inp_loc++] = '5';break;
                case SDLK_6: _g_cons_inp_text[inp_loc++] = '6';break;
                case SDLK_7: _g_cons_inp_text[inp_loc++] = '7';break;
                case SDLK_8: _g_cons_inp_text[inp_loc++] = '8';break;
                case SDLK_9: _g_cons_inp_text[inp_loc++] = '9';break;
                case SDLK_EXCLAIM: _g_cons_inp_text[inp_loc++] = '!';break;
                case SDLK_AT: _g_cons_inp_text[inp_loc++] = '@';break;
                case SDLK_HASH: _g_cons_inp_text[inp_loc++] = '#';break;
                case SDLK_DOLLAR: _g_cons_inp_text[inp_loc++] = '$';break;
                case SDLK_PERCENT: _g_cons_inp_text[inp_loc++] = '%';break;
                case SDLK_POWER: _g_cons_inp_text[inp_loc++] = '^';break;
                case SDLK_AMPERSAND: _g_cons_inp_text[inp_loc++] = '&';break;
                case SDLK_ASTERISK: _g_cons_inp_text[inp_loc++] = '*';break;
                case SDLK_RIGHTPAREN: _g_cons_inp_text[inp_loc++] = '(';break;
                case SDLK_LEFTPAREN: _g_cons_inp_text[inp_loc++] = ')';break;
                case SDLK_MINUS: _g_cons_inp_text[inp_loc++] = '-';break;
                case SDLK_EQUALS: _g_cons_inp_text[inp_loc++] = '=';break;
                case SDLK_PLUS: _g_cons_inp_text[inp_loc++] = '+';break;
                case SDLK_PERIOD: _g_cons_inp_text[inp_loc++] = '.';break;
                case SDLK_UNDERSCORE: _g_cons_inp_text[inp_loc++] = '_';break;
                case SDLK_SPACE: _g_cons_inp_text[inp_loc++] = ' ';break;
                case SDLK_BACKSPACE: {
                    if(inp_loc != 0) _g_cons_inp_text[--inp_loc] = ' ';
                }break;
                case SDLK_RETURN: _g_enter_cmd = 1; inp_loc = 0; break;
            }
        }
    }
}
