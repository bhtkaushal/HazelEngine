#include "hzpch.h"
#include "MacOSWindow.h"

namespace Hazel {
    static bool glfwInitialized = false;

    Window *Window::create(const WindowProperties& properties) {
        return new MacOSWindow(properties);
    }

    MacOSWindow::MacOSWindow(const WindowProperties& properties) {
        MacOSWindow::init(properties);
    }

    MacOSWindow::~MacOSWindow() {
        MacOSWindow::shutdown();
    }

    void MacOSWindow::init(const WindowProperties& properties) {
        data.width = properties.width;
        data.height = properties.height;
        data.title = properties.title;
        HZ_CORE_INFO("Creating window {0} ({1}, {2})", properties.title, properties.width, properties.height);

        if (!glfwInitialized) {
            auto success = glfwInit();
            HZ_CORE_ASSERT(success, "GLFW couldn't be initialized.");
            glfwInitialized = true;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        window = glfwCreateWindow(
            static_cast<int>(data.width),
            static_cast<int>(data.height),
            data.title.c_str(),
            nullptr,
            nullptr
        );
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, &data);
        setVSync(true);
    }

    void MacOSWindow::shutdown() {
        glfwDestroyWindow(window);
    }

    void MacOSWindow::onUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    bool MacOSWindow::isVSync() {
        return data.vsync;
    }

    void MacOSWindow::setVSync(bool enabled) {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        data.vsync = enabled;
    }
}
