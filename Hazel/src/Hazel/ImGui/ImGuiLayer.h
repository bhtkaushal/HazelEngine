#pragma once

#include "Hazel/Core.h"
#include "Hazel/Layer.h"

namespace Hazel {
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
        float Time = 0.0f;
    };
}
