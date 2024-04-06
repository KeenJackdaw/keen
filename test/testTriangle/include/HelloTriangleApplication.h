//
// Created by app on 3/9/24.
//

#ifndef KEEN_HELLOTRIANGLEAPPLICATION_H
#define KEEN_HELLOTRIANGLEAPPLICATION_H

#define GLFW_INCLUDE_VULKAN
// this way GLFW will include its own definitions and automatically load the Vulkan header with it

#include <stdexcept>
#include <vector>
#include <iostream>
#include <cstring>
#include <optional>
#include <set>
#include <limits>
#include <algorithm>
#include <fstream>
#include <GLFW/glfw3.h>


struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() const {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class HelloTriangleApplication {
private:
    GLFWwindow* window = nullptr;

    VkInstance instance{};
    VkDebugUtilsMessengerEXT debugMessenger;

    const int32_t WIDTH = 800;
    const int32_t HEIGHT = 600;

    const std::vector<const char*> validationLayers = {"VK_LAYER_KHRONOS_validation"};
    const std::vector<const char*> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device{};

    VkQueue graphicsQueue{};

    VkSurfaceKHR surface;
    VkQueue presentQueue;

    VkSwapchainKHR swapChain;

    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanUp();
    }
private:
    void createInstance();
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanUp();

    bool checkValidationLayerSupport();
    std::vector<const char *> getRequiredExtensions() const;

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData);

    void setupDebugMessenger();
    static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    void pickPhysicalDevice();

    void createLogicalDevice();

    void createSurface();

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    bool isDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface, std::vector<const char*> deviceExtensions);

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);

    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);

    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    void createSwapChain();

    void createImageViews();

    void createGraphicsPipeline();

    VkShaderModule createShaderModule(const std::vector<char> &code);
};


#endif //KEEN_HELLOTRIANGLEAPPLICATION_H
