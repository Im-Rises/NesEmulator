#include <GLFW/glfw3.h>
#include <cstdio>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"

int main() {
    if (!glfwInit())
        return 1;
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+Metal example", NULL, NULL);
    if (window == NULL)
        return 1;
    // glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();

    bool show_another_window = false;

    ImGui_ImplGlfw_InitForOpenGL(window, true);

    while (!glfwWindowShouldClose(window)) {
        ImGui::ShowDemoWindow(&show_another_window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
