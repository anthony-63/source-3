#include "agt_dev_console.h"
#include "agt_input.h"
#include <stdio.h>
#define DEV_CONSOLE_LINES_AMOUNT 16
TTF_Font* font = NULL;
SDL_Color txt_color = {0, 0, 0};
SDL_Color txt_dat_color = {210, 210, 210};
char *_g_cons_inp_text;
extern int _g_show_cons;
extern int _g_enter_cmd;
SDL_Surface* _g_cons_dat_text[DEV_CONSOLE_LINES_AMOUNT + 1];
int cons_dat_curr_idx = 0;
void agt_setup_dev_console() {
    font = TTF_OpenFont("fonts/font.ttf", 16);
    if(font == NULL) {
        printf("[ERROR] Failed to load font from fonts/font.ttf\n");
    }
    printf("LOADED FONT!\n");
    _g_cons_inp_text = (char*)malloc(sizeof(char) * 4096);
    memset(_g_cons_inp_text, 0, sizeof(char) * 4096);
}

// should not need to pass in as a pointer but i want to do more evil memory stuff
void agt_draw_dev_console(AGT_Window* win, SDL_Event ev) {
    if(!_g_show_cons) return;
    SDL_Surface *inp_text_surf = TTF_RenderText_Solid(font, _g_cons_inp_text, txt_color);
    
    if(_g_enter_cmd){
        _g_enter_cmd = 0;
        if(cons_dat_curr_idx + 3 >= DEV_CONSOLE_LINES_AMOUNT) {
            printf("REACHED END!\n");
            for(int i = DEV_CONSOLE_LINES_AMOUNT; i > 1; i--) {
                _g_cons_dat_text[i - 1] = _g_cons_dat_text[i]; 
            }
            cons_dat_curr_idx--;
        }
        _g_cons_dat_text[cons_dat_curr_idx++] = TTF_RenderText_Solid(font, _g_cons_inp_text, txt_dat_color);
        memset(_g_cons_inp_text, 0, sizeof(char) * 4096);
    }
    
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