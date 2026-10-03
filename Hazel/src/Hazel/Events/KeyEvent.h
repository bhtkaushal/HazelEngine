#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"
#include "Events.h"

namespace Hazel {
    class HAZEL_API KeyEvent: public Event {
    public:
        [[nodiscard]] inline int getKeyCode() const { return keycode; }
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

    protected:
        explicit KeyEvent(const int keycode)
            :keycode(keycode) {}
        int keycode;
    };

    class HAZEL_API KeyPressedEvent: public KeyEvent {
    public:
        KeyPressedEvent(const int keycode, const int repeatCount)
            :KeyEvent(keycode),repeatCount(repeatCount) {}

        [[nodiscard]] int getRepeatCount() const {
            return repeatCount;
        }
        [[nodiscard]] std::string toString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << keycode << " (" << repeatCount << " repeats)";
            return  ss.str();
        }
        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int repeatCount;
    };

    class HAZEL_API KeyReleasedEvent: public KeyEvent {
    public:
        explicit KeyReleasedEvent(const int keycode)
            :KeyEvent(keycode) {}

        [[nodiscard]] std::string toString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent:" << keycode;
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyReleased)
    };
}