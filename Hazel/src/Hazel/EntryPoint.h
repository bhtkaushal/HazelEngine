#pragma once

#ifdef HZ_PLATFORM_MACOS
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
    Hazel::Log::Init();
    HZ_CORE_WARN("Initializing Logger...");
    HZ_INFO("Hazel Engine!");
    const auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}
#endif
