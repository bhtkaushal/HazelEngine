#pragma once

#include "Hazel/Core.h"

namespace Hazel {
    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication = BIN(0),
        EventCategoryInput = BIN(1),
        EventCategoryKeyboard = BIN(2),
        EventCategoryMouse = BIN(3),
        EventCategoryMouseButton = BIN(4),
    };

#define EVENT_CLASS_TYPE(type)  static EventType getStaticType() { return EventType::type; }\
                                virtual EventType getEventType() const override { return getStaticType(); }\
                                virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getEventCategoryFlag() const override { return category; }



    class HAZEL_API Event {
    public:
        friend class EventDispatcher;

        virtual ~Event() = default;

        [[nodiscard]] virtual EventType getEventType() const = 0;
        [[nodiscard]] virtual const char* getName() const = 0;
        [[nodiscard]] virtual int getEventCategoryFlag() const  = 0;
        [[nodiscard]] inline virtual std::string toString() const { return getName(); }

        [[nodiscard]] inline bool isInCategory(const EventCategory category) const {
            return getEventCategoryFlag() & category;
        }
    protected:
        bool handled = false;
    };

    class HAZEL_API EventDispatcher {
    public:
        template<typename T>
        using eventFn = std::function<bool(T&)>;

        explicit EventDispatcher(Event& event)
            :event(event) {}

        template<typename T>
        bool Dispatcher(eventFn<T> fn) {
            if (event.getEventType() == T::getStaticType()) {
                event.handled = fn(*reinterpret_cast<T*>(&event));
                return true;
            }
            return false;
        }
    private:
        Event& event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e) {
        return os << e.toString();
    }
}