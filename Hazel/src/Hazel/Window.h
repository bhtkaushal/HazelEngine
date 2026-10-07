#pragma once

#include "hzpch.h"

#include "Core.h"
#include "Events/Events.h"

namespace Hazel {
    struct WindowProperties {
        unsigned int width;
        unsigned int height;
        std::string title;

        explicit WindowProperties(
            const int width = 1280,
            const int height = 720 ,
            std::string title = "Hazel Engine"
        )
            :width(width), height(height), title(std::move(title)) {
        }
    };

    // Interface representing a desktop system based Window;
    class HAZEL_API Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void onUpdate() = 0;
        virtual int getWidth() = 0;
        virtual int getHeight() = 0;

        // Window attributes;
        virtual void setEventCallback(const EventCallbackFn &callbackFn) = 0;
        virtual void setVSync(bool enabled) = 0;
        virtual bool isVSync() = 0;

        static Window* create(const WindowProperties &properties = WindowProperties());
    };
}
