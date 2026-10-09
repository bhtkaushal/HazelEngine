#pragma once

#include "hzpch.h"
#include "Core.h"
#include "Layer.h"

namespace Hazel {
    class HAZEL_API LayerStack {
    public:
        LayerStack();
        ~LayerStack();

        void pushLayer(Layer* layer);
        void poplayer(Layer* layer);
        void pushOverlay(Layer* overlay);
        void popOverlay(Layer* overlay);

        inline std::vector<Layer*>::iterator begin() { return layers.begin(); }
        inline std::vector<Layer*>::iterator end() { return layers.end(); }

    private:
        std::vector<Layer*> layers;
        std::vector<Layer*>::iterator layerInsert;
    };
}
