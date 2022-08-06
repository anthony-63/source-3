#pragma once
#include <SDL2/SDL.h>
typedef struct AGT_Window AGT_Window;
typedef struct AGT_Window {
    SDL_Window* agt_win;
    SDL_Surface* agt_win_surf;
    int w;
    int h;
    // absolutely terrible but i like being unique(maybe a memory leak, i wont check)
    void (*agt_win_callback)(AGT_Window* win);  
} AGT_Window;

// i love C!
AGT_Window* agt_construct_window(char* window_title, int win_width, int win_heighht);
// so beutiful 
void agt_set_win_callback(AGT_Window* win, void (*callback)(AGT_Window* win));

void agt_win_start(AGT_Window* win);
