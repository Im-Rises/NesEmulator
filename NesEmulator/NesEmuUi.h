#ifndef DEF_NES_EMU_UI
#define DEF_NES_EMU_UI

struct GLFWwindow;

class NesEmuUi {

private:
	GLFWwindow* window;
	int display_w, display_h;

public:
	NesEmuUi();
	~NesEmuUi();

	void start();
};

#endif
