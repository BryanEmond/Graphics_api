cmake_minimum_required(VERSION 3.24)
project(graphics_api)
find_package(Vulkan REQUIRED)

add_library(
        ${PROJECT_NAME}
        graphics_api.h
        graphics_api.cpp
        vulkan_api.h
        vulkan_api.cpp
)

include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
)
FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()
#FetchContent_Declare(
#        glad
#        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
#)
#
##FetchContent_GetProperties(glad)
##if(NOT glad_POPULATED)
##    FetchContent_Populate(glad)
##    set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
##    set(GLAD_API "gl=" CACHE STRING "API type/version pairs, like \"gl=3.2,gles=\", no version means latest")
##    set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")
##    add_subdirectory(${glad_SOURCE_DIR} ${glad_BINARY_DIR})
##endif()
#
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
)

FetchContent_GetProperties(glm)
if(NOT glm_POPULATED)
    FetchContent_Populate(glm)
    add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
endif()

target_link_libraries(${PROJECT_NAME} glfw glm Vulkan::Vulkan )

#add_subdirectory(Window)
#target_link_libraries(${PROJECT_NAME} PUBLIC Window)
