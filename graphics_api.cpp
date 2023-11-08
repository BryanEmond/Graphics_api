#define GLFW_INCLUDE_VULKAN

#include "graphics_api.h"
#include <GLFW/glfw3.h>

namespace graphics_api{
    void graphics_api::run(){}
    void graphics_api::initWindow(){
        glfwInit();

        //remove opengl context
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        //not resizable
//        glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);

        //window creation
        //params 4: specify a monitor to open the window
        //params 5: only relevant to OpenGL
        window = glfwCreateWindow(WIDTH,HEIGHT,"Engine", nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    }
    void graphics_api::mainLoop() {
        while(!glfwWindowShouldClose(window)){
            glfwPollEvents();
        }
    }
    void graphics_api::cleanup() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    void graphics_api::framebufferResizeCallback(GLFWwindow* window, int width, int height){
        auto app = reinterpret_cast<graphics_api*>(glfwGetWindowUserPointer(window));
        app->framebufferResized = true;
    }

}


