#include "hzpch.h"
#include "MacOSWindow.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"

namespace Hazel {
    static bool glfwInitialized = false;
    static void glfwErrorCallback(int error, const char* description) {
        HZ_CORE_ERROR("GLFW Error {0}: {1}", error, description);
    }

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
            [[maybe_unused]] auto success = glfwInit();
            HZ_CORE_ASSERT(success, "GLFW couldn't be initialized.");
            glfwSetErrorCallback(glfwErrorCallback);
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

        // GLFW Callbacks;

        // Resize Event;
        glfwSetWindowSizeCallback(window, [](GLFWwindow* window, const int width, const int height) {
            auto data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            data.width = width;
            data.height = height;

            WindowResizeEvent event(static_cast<float>(width), static_cast<float>(height));
            data.eventCallback(event);
        });

        // Close Event;
        glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
            const auto data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            WindowCloseEvent event;
            data.eventCallback(event);
        });

        // Key Event;
        glfwSetKeyCallback(window, [](GLFWwindow* window, const int key, int scancode, int action, int mods) {
            const auto data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, 1);
                    data.eventCallback(event);
                    break;
                }
                default:
                    break;
            }
        });

        // Mouse Event;
        glfwSetMouseButtonCallback(window, [](GLFWwindow* window, const int button, const int action, const int mods) {
            const auto data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data.eventCallback(event);
                    break;
                }
                default:
                    break;
            }
        });

        // Scroll Event;
        glfwSetScrollCallback(window, [](GLFWwindow* window, const double xoffset, const double yoffset) {
            const auto data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            MouseScrollEvent event(static_cast<float>(xoffset), static_cast<float>(yoffset));
            data.eventCallback(event);
        });

        // Mouse-moved Event;
        glfwSetCursorPosCallback(window, [](GLFWwindow* window, const double xpos, const double ypos) {
            const auto data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            MouseMovedEvent event(static_cast<float>(xpos), static_cast<float>(ypos));
            data.eventCallback(event);
        });
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
