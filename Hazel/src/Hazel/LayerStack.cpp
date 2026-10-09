#include "hzpch.h"
#include "LayerStack.h"

namespace Hazel {
    LayerStack::LayerStack() {
        layerInsert = layers.begin();
    }

    LayerStack::~LayerStack() {
        for (const auto layer: layers)
            delete layer;
    }

    void LayerStack::pushLayer(Layer* layer) {
        layerInsert = layers.emplace(layerInsert, layer);
    }

    void LayerStack::poplayer(Layer* layer) {
        if (const auto it = std::ranges::find(layers, layer); it != layers.end()) {
            layers.erase(it);
            --layerInsert;
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
