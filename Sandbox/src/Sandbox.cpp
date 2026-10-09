#include <Hazel.h>

namespace {
    class LayerInstance: public Hazel::Layer {
    public:
        LayerInstance()
            :Layer("Test") {}

        void onUpdate() override {
            HZ_INFO("TestLayer::Update");
        }

        void onEvent(Hazel::Event &event) override {
            HZ_TRACE("{0}", event.toString());
        }
    };

    class Sandbox : public Hazel::Application {
    public:
        Sandbox() { pushLayer(new LayerInstance()); }
        ~Sandbox() override = default;
    };
}

Hazel::Application *Hazel::CreateApplication() {
    return new Sandbox();
}
