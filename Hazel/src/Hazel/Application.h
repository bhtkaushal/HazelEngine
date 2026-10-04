#pragma once

#include "Core.h"
#include "Window.h"

namespace Hazel {
    class HAZEL_API Application {
    public:
        Application();
        virtual ~Application();

        void Run() const;

    private:
        std::unique_ptr<Window> window;
        bool running = true;
    };
    // Implemented in CLIENT;
    Application* CreateApplication();

}
