#include "agt_callback.h"
#include "agt_dev_console.h"
#include "agt_input.h"
#include "agt_gvars.h"
extern AGT_gvars* gvars;
extern int _g_show_cons;
void cleanup(AGT_Window* win) {
    SDL_DestroyWindow(win->agt_win);
    // i dont know if this really does anything
    free(win);
    TTF_Quit();
    SDL_Quit();
    exit(0);
}

void draw(AGT_Window* win) {
    SDL_FillRect(win->agt_win_surf, NULL, agt_gvar_access(gvars, "bg.color"));
}


void agt_win_callback(AGT_Window* win) {
    SDL_Event ev;
    while(1){
        if(SDL_PollEvent(&ev)) {
            switch(ev.type) {
                // lel, ez way to quit
                case SDL_QUIT: cleanup(win); break;
                case SDL_KEYDOWN:
                    agt_input_handler(ev);
                default: break;
            }
        }
        draw(win);
        agt_draw_dev_console(win, ev);
        SDL_UpdateWindowSurface(win->agt_win);
    }
}
