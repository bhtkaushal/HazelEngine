#pragma once

#include <utility>

#include "hzpch.h"
#include "Core.h"
#include "Hazel/Events/Events.h"

namespace Hazel {
    class HAZEL_API Layer {
    public:
        explicit Layer(std::string  name);
        virtual ~Layer();

        virtual void onAttach() {};
        virtual void onDetach() {};
        virtual void onUpdate() {};
        virtual void onEvent(Event& event) = 0;

        [[nodiscard]] inline std::string getName() const { return debugName; }
    private:
        std::string debugName;
    };
}
