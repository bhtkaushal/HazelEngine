#pragma once

#include "Hazel/Core.h"
#include "Hazel/Layer.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"

namespace Hazel {
    class HAZEL_API ImGuiLayer: public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override;

        void onAttach() override;
        void onDetach() override;
        void onEvent(Event& event) override;
        void onImGuiRender() override;

        virtual void begin();
        virtual void end();

    private:
        float Time = 0.0f;
        bool block = true;
    };
}
