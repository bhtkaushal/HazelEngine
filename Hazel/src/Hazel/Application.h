#pragma once

#include "Core.h"
#include "Window.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/Events.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "ImGui/ImGuiLayer.h"

namespace Hazel {
    class HAZEL_API Application {
    public:
        Application();
        virtual ~Application();

        void run();
        inline static Application& get() { return *instance; }
        [[nodiscard]] inline Window& getWindow() const { return *window; }
        void pushLayer(Layer *layer);
        void pushOverlay(Layer *layer);
        void onEvent(Event& e);

    private:
        bool onWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> window;
        bool running = true;
        LayerStack layerStack;
        ImGuiLayer* imGuiLayer{};

    private:
        static Application* instance;
    };

    // Implement in CLIENT;
    Application* CreateApplication();

}
