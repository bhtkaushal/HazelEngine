#pragma once

#include "Core.h"
#include "Events/Events.h"

namespace Hazel {
    class HAZEL_API Application {
    public:
        Application();
        virtual ~Application();

        static void Run();
    };
    // Implemented in CLIENT;
    Application* CreateApplication();
}
