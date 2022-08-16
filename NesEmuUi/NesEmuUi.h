#ifndef DEF_NES_EMU_UI
#define DEF_NES_EMU_UI

struct GLFWwindow;

class NesEmuUi {

private:
	GLFWwindow* window;

public:
	NesEmuUi();
	~NesEmuUi();

	void start();
};

#endif
