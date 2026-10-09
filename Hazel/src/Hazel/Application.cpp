#include "hzpch.h"
#include "Application.h"

#include <ranges>
#include <GLFW/glfw3.h>


namespace Hazel {
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
    Application::Application() {
        window = std::unique_ptr<Window>(Window::create());
        window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
    };
    Application::~Application() = default;

    void Application::run() {
        while (running) {
            glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer: layerStack) {
                layer->onUpdate();
            }
            window->onUpdate();
        }
    }

    void Application::onEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));
        HZ_CORE_TRACE("{0}", e.toString());

        // for (auto it = layerStack.end(); it != layerStack.begin();) {
        for(auto* it: layerStack | std::views::reverse) {
            // (*--it)->onEvent(e); // redact if diff-loop is used;
            if (e.handled)
                break;
        }
    }

    bool Application::onWindowClose(WindowCloseEvent& e) {
        running = false;
        return true;
    }

    void Application::pushLayer(Layer *layer) {
        layerStack.pushLayer(layer);
    }

    void Application::pushOverlay(Layer *layer) {
        layerStack.popOverlay(layer);
    }
}
