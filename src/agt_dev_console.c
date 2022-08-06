#include "agt_dev_console.h"
#include "agt_input.h"
#include "agt_gvars.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEV_CONSOLE_LINES_AMOUNT 16

TTF_Font* font = NULL;
SDL_Color txt_color = {0, 0, 0};
SDL_Color txt_dat_color = {230, 230, 230};
char *_g_cons_inp_text;
extern int _g_show_cons;
extern int _g_enter_cmd;
SDL_Surface* _g_cons_dat_text[DEV_CONSOLE_LINES_AMOUNT + 1];
extern AGT_gvars *gvars;
int cons_dat_curr_idx = 0;

void slice(const char *str, char *result, size_t start, size_t end){
    strncpy(result, str + start, end - start);
}

void agt_setup_dev_console() {
    font = TTF_OpenFont("fonts/font1.ttf", 16);
    if(font == NULL) {
        printf("[ERROR] Failed to load font from fonts/font.ttf\n");
    }
    printf("LOADED FONT!\n");
    _g_cons_inp_text = (char*)malloc(sizeof(char) * 4096);
    memset(_g_cons_inp_text, 0, sizeof(char) * 4096);
}

void agt_draw_dev_console(AGT_Window* win, SDL_Event ev) {
    if(!_g_show_cons) return;
    SDL_Surface *inp_text_surf = TTF_RenderText_Blended(font, _g_cons_inp_text, txt_color);
    
    if(_g_enter_cmd){
        _g_enter_cmd = 0;
        if(cons_dat_curr_idx >= DEV_CONSOLE_LINES_AMOUNT) {
            memset(_g_cons_dat_text, 0, sizeof(_g_cons_dat_text));
            cons_dat_curr_idx = 0;
        }
        char dat_msg[128];
        sprintf(dat_msg, "> %s", _g_cons_inp_text);
        _g_cons_dat_text[cons_dat_curr_idx++] = TTF_RenderText_Blended(font, dat_msg, txt_dat_color);

        // this is insanely terrible, but i dont care, it works.
        char cmd_buf[5];
        slice(_g_cons_inp_text, cmd_buf, 0, 4);
        cmd_buf[5] = '\0';
        printf("command: '%s'\n", cmd_buf);
        if(strcmp("gset", cmd_buf) == 0) {
            printf("gset called\n");
            char arg_buf[9];
            slice(_g_cons_inp_text, arg_buf, 5, 13);
            arg_buf[8] = '\0';
            printf("gset args: %s\n", arg_buf);
            if(strcmp(arg_buf, "bg.color") == 0) {
                char bg_str_amm[9];
                slice(_g_cons_inp_text, bg_str_amm, 14, 22);
                bg_str_amm[8] = '\0';
                int bg_amm = strtol(bg_str_amm, NULL, 16);
                agt_gvar_set(gvars, arg_buf, bg_amm);
                char dbg_msg[128];
                sprintf(dbg_msg, "] Set background color to %06X", bg_amm);
                _g_cons_dat_text[cons_dat_curr_idx++] = TTF_RenderText_Blended(font, dbg_msg, txt_dat_color);
            }
        }

        memset(_g_cons_inp_text, 0, sizeof(char) * 4096);
    }
    
    // repeating code is fine, as long as it works ;)
    SDL_Rect console_border_rect = {20, 0, win->w - 40, win->h - 200};
    SDL_Rect text_input_rect =     {40, win->h - 245, win->w - 80, 30};
    SDL_Rect console_data_rect =   {40, 10, win->w - 80, win->h - 270};
    SDL_Rect inp_text_rect =       {text_input_rect.x + 5, text_input_rect.y + 5, 0, 0};
    SDL_FillRect(win->agt_win_surf, &console_border_rect, 0x6D6F72);
    SDL_FillRect(win->agt_win_surf, &text_input_rect, 0xFFFFFF);
    SDL_FillRect(win->agt_win_surf, &console_data_rect, 0x35383B);
    SDL_UpperBlit(inp_text_surf, NULL, win->agt_win_surf, &inp_text_rect);
    for(int i = 0; i < DEV_CONSOLE_LINES_AMOUNT; i++) {
        SDL_Rect dat_rect = {console_data_rect.x + 5, console_data_rect.y + 5 + (i * 20)};
        SDL_UpperBlit(_g_cons_dat_text[i], NULL, win->agt_win_surf, &dat_rect);
    }

}