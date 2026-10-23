#include "hzpch.h"
#include "LayerStack.h"

namespace Hazel {
    LayerStack::LayerStack() = default;

    LayerStack::~LayerStack() {
        for (const auto layer: layers)
            delete layer;
    }

    void LayerStack::pushLayer(Layer* layer) {
        layers.emplace(layers.begin() + layerInsertIndex, layer);
        layerInsertIndex++;
    }

    void LayerStack::poplayer(Layer* layer) {
        if (const auto it = std::ranges::find(layers, layer); it != layers.end()) {
            layers.erase(it);
            --layerInsertIndex;
        }
    }

    void LayerStack::pushOverlay(Layer* overlay) {
        layers.emplace_back(overlay);
    }

    void LayerStack::popOverlay(Layer* overlay) {
        if (const auto it = std::ranges::find(layers, overlay); it != layers.end())
            layers.erase(it);
    }
}