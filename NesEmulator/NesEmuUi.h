#ifndef DEF_NES_EMU_UI
#define DEF_NES_EMU_UI

#define VER 0.1
#define AUTHOR "Im-Rises"
#define PROJECT_NAME "NesEmulator"

#include <SDL.h>

// struct SDL_Window;

class NesEmuUi {

private:
    SDL_Window* window;
    SDL_GLContext gl_context;
    //    int display_w, display_h;

public:
    NesEmuUi();
    ~NesEmuUi();

    void start();
};

#endif
