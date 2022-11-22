#include "NesEmuUi.h"

//#include "Nes/Nes.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <cstdio>
#include <cstdlib>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

NesEmuUi::NesEmuUi() {
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        exit(1);

        // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    window = glfwCreateWindow(windowWidth, windowHeight, PROJECT_NAME, NULL, NULL);
    if (window == NULL)
        exit(1);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;   // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows
    // io.ConfigViewportsNoAutoMerge = true;
    // io.ConfigViewportsNoTaskBarIcon = true;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Set clear color
    backgroundColor = { 0.45f, 0.55f, 0.60f, 1.00f };

    // Create a new NesEmulator
    //    nes = Nes::getInstance();
}

NesEmuUi::~NesEmuUi() {
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

void NesEmuUi::start() {
    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        updateInput();
        updateGui();
        updateGame();
        updateRender();
    }
}

void NesEmuUi::updateInput() {
    glfwPollEvents();
}

void NesEmuUi::updateGui() {
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    {
        static bool my_tool_active = true;
        static bool showAboutPopup = false;
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Open..", "Ctrl+O"))
                { /* Do stuff */
                }
                if (ImGui::MenuItem("Save", "Ctrl+S"))
                { /* Do stuff */
                }
                if (ImGui::MenuItem("Close", "Ctrl+W"))
                { my_tool_active = false; }
                if (ImGui::MenuItem("Exit", "Alt+F4"))
                { glfwSetWindowShouldClose(window, true); }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("View"))
            {
                if (ImGui::MenuItem("FullScreen", "F11"))
                {
                    // toggleFullScreen();
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Emulation"))
            {
                if (ImGui::MenuItem("Pause", "F5"))
                {
                    // togglePause();
                }
                if (ImGui::MenuItem("Reset", "F6"))
                {
                    // reset();
                }
                if (ImGui::MenuItem("Save State", "F7"))
                {
                    // saveState();
                }
                if (ImGui::MenuItem("Load State", "F8"))
                {
                    // loadState();
                }
                if (ImGui::MenuItem("Settings", "F9"))
                {
                    // showSettings();
                }
                if (ImGui::MenuItem("Debugger", "F10"))
                {
                    // showDebugger();
                }
                if (ImGui::MenuItem("Turbo", "F12"))
                {
                    // toggleTurbo();
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Help"))
            {
                if (ImGui::MenuItem("About " PROJECT_NAME))
                {
                    showAboutPopup = true;
                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
        if (showAboutPopup)
            ImGui::OpenPopup("About " PROJECT_NAME "##AboutPopup");
        if (ImGui::BeginPopupModal("About " PROJECT_NAME "##AboutPopup", &showAboutPopup,
                ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize |
                    ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse))
        {
            ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), PROJECT_NAME);
            ImGui::Text("Version: %s", PROJECT_VERSION);
            ImGui::NewLine();
            ImGui::Text("Developed by: ");
            ImGui::Text(AUTHOR);
            ImGui::NewLine();
            ImGui::Text("Github: %s", PROJECT_GITHUB);
            ImGui::NewLine();
            if (ImGui::Button("Close"))
            {
                ImGui::CloseCurrentPopup();
                showAboutPopup = false;
            }
            ImGui::EndPopup();
        }
    }
}

void NesEmuUi::updateGame() {
}

void NesEmuUi::updateRender() {
    // Rendering
    ImGui::Render();
    glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
    glViewport(0, 0, windowWidth, windowHeight);
    //    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClearColor(backgroundColor[0] * backgroundColor[3], backgroundColor[1] * backgroundColor[3], backgroundColor[2] * backgroundColor[3], backgroundColor[3]);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }

    glfwSwapBuffers(window);
}

// void NesEmuUi::start() {
//	bool show_demo_window = true;
//	bool show_another_window = false;
//	int refresRate = 60;
//	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//
//	float fps = 60;
//	static MemoryEditor mem_edit_1;
//	static char data[0x10000];
//	size_t data_size = 0x10000;
//
//	imgui_addons::ImGuiFileBrowser file_dialog; // As a class member or globally
//	bool open = false, save = false;
//
//	// Main loop
//	while (!glfwWindowShouldClose(window)) {
//		// Poll and handle events (inputs, window resize, etc.)
//		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
//		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
//		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
//		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
//		glfwPollEvents();
//
//		// Start the Dear ImGui frame
//		ImGui_ImplOpenGL3_NewFrame();
//		ImGui_ImplGlfw_NewFrame();
//		ImGui::NewFrame();
//
//		mem_edit_1.DrawWindow("Ram Editor", data, data_size);
//
//		mem_edit_1.DrawWindow("Cartridge hex view", data, data_size);
//
//		int test_reg = 0;
//
//		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
//		{
//			static float f = 0.0f;
//			static int counter = 0;
//
//			ImGui::Begin("CPU registers"); // Create a window called "Hello, world!" and append into it.
//
//			ImGui::Text("A :    ");
//			ImGui::SameLine();
//			ImGui::InputScalar("##DT", ImGuiDataType_U8, &test_reg, NULL, NULL, "%02X", ImGuiInputTextFlags_CharsHexadecimal);
//
//			ImGui::Text("B :    ");
//			ImGui::SameLine();
//			ImGui::InputScalar("##DT", ImGuiDataType_U8, &test_reg, NULL, NULL, "%02X", ImGuiInputTextFlags_CharsHexadecimal);
//
//			ImGui::Text("C :    ");
//			ImGui::SameLine();
//			ImGui::InputScalar("##DT", ImGuiDataType_U8, &test_reg, NULL, NULL, "%02X", ImGuiInputTextFlags_CharsHexadecimal);
//
//			ImGui::Text("D :    ");
//			ImGui::SameLine();
//			ImGui::InputScalar("##DT", ImGuiDataType_U8, &test_reg, NULL, NULL, "%02X", ImGuiInputTextFlags_CharsHexadecimal);
//
//			ImGui::Text("E :    ");
//			ImGui::SameLine();
//			ImGui::InputScalar("##DT", ImGuiDataType_U8, &test_reg, NULL, NULL, "%02X", ImGuiInputTextFlags_CharsHexadecimal);
//
//			ImGui::Text("H :    ");
//			ImGui::SameLine();
//			ImGui::InputScalar("##DT", ImGuiDataType_U8, &test_reg, NULL, NULL, "%02X", ImGuiInputTextFlags_CharsHexadecimal);
//
//			ImGui::Text("L :    ");
//			ImGui::SameLine();
//			ImGui::InputScalar("##DT", ImGuiDataType_U8, &test_reg, NULL, NULL, "%02X", ImGuiInputTextFlags_CharsHexadecimal);
//
//			ImGui::Text("PC :   ");
//			ImGui::SameLine();
//			ImGui::InputScalar("##DT", ImGuiDataType_U8, &test_reg, NULL, NULL, "%02X", ImGuiInputTextFlags_CharsHexadecimal);
//
//			ImGui::Text("STAT : ");
//			ImGui::SameLine();
//			ImGui::InputScalar("##DT", ImGuiDataType_U8, &test_reg, NULL, NULL, "%02X", ImGuiInputTextFlags_CharsHexadecimal);
//
//			ImGui::End();
//		}
//
//		{
//			ImGui::Begin("Disassembler");
//			ImGui::End();
//		}
//
//		{
//			ImGui::Begin("Controller");
//			ImGui::Button("Run");
//			ImGui::Button("Break");
//			ImGui::Button("Step");
//			ImGui::SliderInt("Refresh Rate", &refresRate, 30, 120);
//			ImGui::End();
//		}
//
//		{
//			ImGui::Begin("Sprite memory view");
//			ImGui::End();
//		}
//
//		{
//			ImGui::Begin("Background memory view");
//			ImGui::End();
//		}
//
//		{
//			ImGui::Begin("Input Viewer");
//			ImGui::End();
//		}
//
//		{
//			ImGui::Begin("Game View");
//			ImGui::End();
//		}
//
//		{
//			if (ImGui::BeginMainMenuBar()) {
//				if (ImGui::BeginMenu("Menu")) {
//					if (ImGui::MenuItem("Open", NULL))
//						open = true;
//					if (ImGui::MenuItem("Save", NULL))
//						save = true;
//
//					ImGui::EndMenu();
//				}
//				ImGui::EndMainMenuBar();
//			}
//
//			// Remember the name to ImGui::OpenPopup() and showFileDialog() must be same...
//			if (open)
//				ImGui::OpenPopup("Open File");
//			if (save)
//				ImGui::OpenPopup("Save File");
//
//			/* Optional third parameter. Support opening only compressed rar/zip files.
//			 * Opening any other file will show error, return false and won't close the dialog.
//			 */
//			if (file_dialog.showFileDialog("Open File", imgui_addons::ImGuiFileBrowser::DialogMode::OPEN, ImVec2(700, 310), ".rar,.zip,.7z")) {
//				std::cout << file_dialog.selected_fn << std::endl;	 // The name of the selected file or directory in case of Select Directory dialog mode
//				std::cout << file_dialog.selected_path << std::endl; // The absolute path to the selected file
//			}
//			if (file_dialog.showFileDialog("Save File", imgui_addons::ImGuiFileBrowser::DialogMode::SAVE, ImVec2(700, 310), ".png,.jpg,.bmp")) {
//				std::cout << file_dialog.selected_fn << std::endl;	 // The name of the selected file or directory in case of Select Directory dialog mode
//				std::cout << file_dialog.selected_path << std::endl; // The absolute path to the selected file
//				std::cout << file_dialog.ext << std::endl;			 // Access ext separately (For SAVE mode)
//																	 // Do writing of files based on extension here
//			}
//		}
//
//		// Rendering
//		ImGui::Render();
//		int display_w, display_h;
//		glfwGetFramebufferSize(window, &display_w, &display_h);
//		glViewport(0, 0, display_w, display_h);
//		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
//		glClear(GL_COLOR_BUFFER_BIT);
//		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//
//		glfwSwapBuffers(window);
//	}
// }
