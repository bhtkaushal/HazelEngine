#include "Layer.h"

namespace Hazel {
    Layer::Layer(std::string  name)
        :debugName(std::move(name)) {}

    Layer::~Layer() = default;
}
