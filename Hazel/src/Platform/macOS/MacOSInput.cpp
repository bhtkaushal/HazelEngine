#include "hzpch.h"
#include "MacOSInput.h"
#include "GLFW/glfw3.h"
#include "Hazel/Application.h"

namespace Hazel {
    Input* Input::instance = new MacOSInput();

    bool MacOSInput::isKeyPressedImpl(int keycode) {
        auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
        int status = glfwGetKey(window, keycode);
        return status == GLFW_PRESS || status == GLFW_REPEAT;
    }

    bool MacOSInput::isMouseButtonPressedImpl(int button) {
        auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
        int status = glfwGetMouseButton(window, button);
        return status == GLFW_PRESS || status == GLFW_REPEAT;
    }

    std::pair<float, float> MacOSInput::getMousePositionImpl() {
        auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return {static_cast<float>(xpos), static_cast<float>(ypos)};
    }

    float MacOSInput::getMouseXImpl() {
        auto [x, y] = getMousePositionImpl();
        return x;
    }

    float MacOSInput::getMouseYImpl() {
        auto [x, y] = getMousePositionImpl();
        return y;
    }
}
