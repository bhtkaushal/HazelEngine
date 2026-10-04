#include "hzpch.h"
#include "Application.h"
#include <GLFW/glfw3.h>

namespace Hazel {
    Application::Application() {
        window = std::unique_ptr<Window>(Window::create());
    };
    Application::~Application() = default;

    void Application::Run() const {
        while (running) {
            glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            window->onUpdate();
        }
    }
}
