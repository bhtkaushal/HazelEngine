#pragma once

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Hazel {
    class HAZEL_API Application {
    public:
        Application();
        virtual ~Application();

        void Run() const;

        bool onWindowClose(WindowCloseEvent &e);

        void onEvent(Event& e);

    private:
        std::unique_ptr<Window> window;
        bool running = true;
    };
    // Implemented in CLIENT;
    Application* CreateApplication();

}
