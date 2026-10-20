#pragma once

#include "Hazel/Core.h"
#include "Hazel/Layer.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"

namespace Hazel {
    class WindowResizeEvent;

    class HAZEL_API ImGuiLayer: public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override;

        void onAttach() override;
        void onDetach() override;
        void onEvent(Event& event) override;

        void begin();
        void end();
        void onRender();

    private:
        bool onMouseButtonPressedEvent(const MouseButtonPressedEvent& event);
        bool onMouseButtonReleasedEvent(const MouseButtonReleasedEvent& event);
        bool onMouseScrollEvent(const MouseScrollEvent& event);
        bool onMouseMovedEvent(const MouseMovedEvent& event);
        bool onKeyPressedEvent(const KeyPressedEvent& event);
        bool onKeyReleasedEvent(const KeyReleasedEvent& event);
        bool onKeyTypedEvent (const KeyTypedEvent& event);
        bool onWindowResizeEvent(const WindowResizeEvent& event);

    private:
        float Time = 0.0f;
        bool block = true;
    };
}
