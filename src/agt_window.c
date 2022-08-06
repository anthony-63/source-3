#include "agt_window.h"
#include <stdlib.h>
#include <stdio.h>
AGT_Window* agt_construct_window(char* window_title, int win_width, int win_height) {
    AGT_Window* agt_win = (AGT_Window*)malloc(sizeof(AGT_Window*));
    agt_win->w = win_width;
    agt_win->h = win_height;
    agt_win->agt_win = SDL_CreateWindow(window_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_width, win_height, SDL_WINDOW_SHOWN);
    if(!agt_win->agt_win){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    agt_win->agt_win_surf = SDL_GetWindowSurface(agt_win->agt_win);
    return agt_win;
}

void agt_set_win_callback(AGT_Window* win, void (*callback)(AGT_Window* win)) {
    win->agt_win_callback = callback;
}

// literally just calls the callback once to give it a jumpstart
void agt_win_start(AGT_Window* win) {
    win->agt_win_callback(win);
}