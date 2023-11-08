#ifndef ENGINE_GRAPHICS_API_H
#define ENGINE_GRAPHICS_API_H
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <GLFW/glfw3.h>


namespace graphics_api{
    enum graphics_api_type{
        VULKAN,
        DIRECT3D,
        OPENGL
    };

    class graphics_api {
    public:
        virtual void run();
    private:
        const uint32_t WIDTH = 800;
        const uint32_t HEIGHT = 600;
        static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    protected:
        GLFWwindow* window;
        bool framebufferResized = false;
        void initWindow();
        virtual void mainLoop();
        virtual void cleanup();
    };
}



#endif //ENGINE_GRAPHICS_API_H
