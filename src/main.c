#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#include "agt_window.h"
#include "agt_callback.h"
#include "agt_logging.h"
#include "agt_dev_console.h"
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    AGT_Window* win = agt_construct_window("a game thing", 800, 600);
    agt_set_win_callback(win, agt_win_callback);
    agt_setup_dev_console();
    agt_win_start(win);

    return 0;
}