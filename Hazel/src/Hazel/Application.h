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
        void pushLayer(Layer *layer);
        void pushOverlay(Layer *layer);
        void onEvent(Event& e);

    private:
        bool onWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> window;
        bool running = true;
        LayerStack layerStack;
    };
    // Implemented in CLIENT;
    Application* CreateApplication();

}
