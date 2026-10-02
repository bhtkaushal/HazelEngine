#pragma once

#include "Hazel/Core.h"
#include "Events.h"

namespace Hazel {
    class HAZEL_API WindowResizeEvent: public Event {
    public:
        WindowResizeEvent(const float width, const float height)
            :windowWidth(width), windowHeight(height) {}

        [[nodiscard]] inline float getWidth() const { return windowWidth; }
        [[nodiscard]] inline float getHeight() const { return windowHeight; }
        [[nodiscard]] std::string toString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << windowWidth << ", " << windowHeight;
            return ss.str();
        }
        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        float windowWidth, windowHeight;
    };

    class HAZEL_API WindowCloseEvent: public Event {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HAZEL_API AppTickEvent: public Event {
    public:
        AppTickEvent() = default;

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HAZEL_API AppUpdateEvent: public Event {
    public:
        AppUpdateEvent() = default;

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HAZEL_API AppRenderEvent: public Event {
    public:
        AppRenderEvent() = default;

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}