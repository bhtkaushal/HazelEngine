#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Hazel {
    Application::Application() = default;
    Application::~Application() = default;

    void Application::Run() {
        const WindowResizeEvent e(1280, 70);
        HZ_TRACE(e.toString());

        while (true);
    }
}
