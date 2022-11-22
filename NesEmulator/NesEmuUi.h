#ifndef DEF_NES_EMU_UI
#define DEF_NES_EMU_UI

#define PROJECT_NAME "NesEmulator"

#define VERSION_MAJOR "0"
#define VERSION_MINOR "0"
#define VERSION_PATCH "2"

#define PROJECT_VERSION VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH

#define PROJECT_GITHUB "https://github.com/Im-Rises/NesEmulator"

#define AUTHOR "Quentin MOREL (IM-Rises)"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#include <array>

struct GLFWwindow;

class Nes;

class NesEmuUi {

private:
    GLFWwindow* window;
    int windowWidth = WINDOW_WIDTH, windowHeight = WINDOW_HEIGHT;
    std::array<float, 4> backgroundColor = { 0.0f, 0.0f, 0.0f, 1.0f };

    Nes* nes;

public:
    NesEmuUi();
    ~NesEmuUi();

    void start();

private:
    void updateInput();
    void updateGui();
    void updateGame();
    void updateRender();
};

#endif
