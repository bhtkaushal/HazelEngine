#include <Hazel.h>
#include "imgui.h"

namespace {
    class LayerInstance: public Hazel::Layer {
    public:
        LayerInstance()
            :Layer("Test") {}

        void onUpdate() override {
            if (Hazel::Input::isKeyPressed(HZ_KEY_TAB))
                HZ_TRACE("Tab key is pressed (poll)!");
        }

        void onImGuiRender() override {
            if (bool status = true; status) {
                ImGui::Begin("Test Overlay", &status);
                ImGui::Text("Metallic-Hazel");
                ImGui::Button("Hazel");
                ImGui::End();
            }
        }

        void onEvent(Hazel::Event &event) override {
            HZ_TRACE("{0}", event.toString());
            if (event.getEventType() == Hazel::EventType::KeyPressed) {
                const auto& e = dynamic_cast<Hazel::KeyPressedEvent&>(event);
                HZ_TRACE("{0}", static_cast<char>(e.getKeyCode()));
            }
        }
    };

    class Sandbox: public Hazel::Application {
    public:
        Sandbox() {
            pushLayer(new LayerInstance());
        }
        ~Sandbox() override = default;
    };
}

Hazel::Application *Hazel::CreateApplication() {
    return new Sandbox();
}
