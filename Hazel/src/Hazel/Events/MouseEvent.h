#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"
#include "Events.h"

namespace Hazel {
    class HAZEL_API MouseMovedEvent: public Event {
    public:
        MouseMovedEvent(const float x, const float y)
            :mouseX(x), mouseY(y) {}

        [[nodiscard]] inline float getX() const { return mouseX; }
        [[nodiscard]] inline float getY() const { return mouseY; }
        [[nodiscard]] std::string toString() const override {
            std::stringstream ss;
            ss << "MouseEvent:" << mouseX << ", " << mouseY;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

    private:
        float mouseX, mouseY;
    };

    class HAZEL_API MouseScrollEvent: public Event {
    public:
        MouseScrollEvent(const float xOffset, const float yOffset)
            :xOffset(xOffset), yOffset(yOffset) {}

        [[nodiscard]] inline float getXOffset() const { return xOffset; }
        [[nodiscard]] inline float getYOffset() const { return yOffset; }
        [[nodiscard]] std::string toString() const override {
            std::stringstream ss;
            ss << "MouseScrollEvent: " << xOffset << ", " << yOffset;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

    private:
        float xOffset, yOffset;
    };

    class HAZEL_API MouseButtonEvent: public Event {
    public:
        [[nodiscard]] inline int getMouseButton() const { return button; }
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

    protected:
        explicit MouseButtonEvent(const int button)
            :button(button) {}
        int button;
    };

    class HAZEL_API MouseButtonPressedEvent: public MouseButtonEvent {
    public:
        explicit MouseButtonPressedEvent(const int button)
            :MouseButtonEvent(button) {}

        [[nodiscard]] std::string toString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class HAZEL_API MouseButtonReleasedEvent: public MouseButtonEvent {
    public:
        explicit MouseButtonReleasedEvent(const int button)
            :MouseButtonEvent(button) {}

        [[nodiscard]] std::string toString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}