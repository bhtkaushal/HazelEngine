#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"

namespace Hazel {
    class HAZEL_API Input {
    public:
        virtual ~Input() = default;

        inline static bool isKeyPressed(int keycode) { return instance->isKeyPressedImpl(keycode); }

        inline static bool isMouseButtonPressed(int button) { return instance->isMouseButtonPressedImpl(button); }
        inline static std::pair<float, float> getMousePosition() { return instance->getMousePositionImpl(); }
        inline static float getMouseX() { return instance->getMouseYImpl(); }
        inline static float getMouseY() { return instance->getMouseYImpl(); }

    protected:
        virtual bool isKeyPressedImpl(int keycode) = 0;

        virtual bool isMouseButtonPressedImpl(int button) = 0;
        virtual std::pair<float, float> getMousePositionImpl() = 0;
        virtual float getMouseXImpl() = 0;
        virtual float getMouseYImpl() = 0;

    private:
        static Input* instance;
    };
}
