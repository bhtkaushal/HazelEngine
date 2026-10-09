#pragma once

#include "Hazel/Window.h"
#include <GLFW/glfw3.h>

namespace Hazel {
   class MacOSWindow: public Window {
   public:
      explicit MacOSWindow(const WindowProperties& properties);
      ~MacOSWindow() override;

      void onUpdate() override;
      inline int getWidth() override { return static_cast<int>(data.width); }
      inline int getHeight() override {return static_cast<int>(data.height); }

      inline void setEventCallback(const EventCallbackFn &callbackFn) override { data.eventCallback = callbackFn; }
      void setVSync(bool enabled) override;
      bool isVSync() override;

   private:
      virtual void init(const WindowProperties& properties);
      virtual void shutdown();

      GLFWwindow* window{};
      struct WindowData {
         std::string title;
         unsigned int width, height;
         bool vsync;

         EventCallbackFn eventCallback;
      };
      WindowData data;
   };
}
