#pragma once

#include "Core.h"
#include "Window.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/Events.h"
#include "Hazel/Events/ApplicationEvent.h"

namespace Hazel {
    class HAZEL_API Application {
    public:
        Application();
        virtual ~Application();

        void run();
        void onEvent(Event& e);
        void pushLayer(Layer* layer);
        void pushOverlay(Layer* layer);

    private:
        bool onWindowClose(WindowCloseEvent &e);

        bool running = true;
        std::unique_ptr<Window> window;
        LayerStack layerStack;
    };

    // Implemented in CLIENT;
    Application* CreateApplication();

}
