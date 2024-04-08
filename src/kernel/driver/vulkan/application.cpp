//
// Created by keen on 4/7/24.
//

#include "kernel/driver/vulkan/application.h"

KNN_NAMESPACE_BEGIN

VkInstance createVKInstance(const char *appName, const char *engineName, uint32_t appVersion, uint32_t apiVersion) {
    VkApplicationInfo appInfo{};

    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = appName;
    appInfo.applicationVersion = appVersion;
    appInfo.pEngineName = engineName;

    if (!checkVKApiVersion(apiVersion)) {
        return nullptr;
    }
    appInfo.apiVersion = apiVersion;

    appInfo.pNext = nullptr;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    VkDebugUtilsMessengerCreateInfoEXT createInfoExt = populateDebugMessengerCreateInfo();
    std::vector<const char *> validationLayers = getValidationLayers();

    if (supportValidation()) {
        createInfo.enabledLayerCount = validationLayers.size();
        createInfo.ppEnabledLayerNames = validationLayers.data();
        createInfo.pNext = &createInfoExt;
    } else {
        createInfo.enabledLayerCount = 0;
        createInfo.ppEnabledLayerNames = nullptr;
    }

    std::vector<const char *> glfwExtensions = getGLFWExtensions();
    std::vector<const char *> validationExtensions = getValidationExtensions();
    std::vector<const char *> extensions(glfwExtensions.size() + validationExtensions.size());
    std::merge(glfwExtensions.begin(), glfwExtensions.end(), validationExtensions.begin(), validationExtensions.end(), extensions.begin());

    createInfo.enabledExtensionCount = extensions.size();
    createInfo.ppEnabledExtensionNames = extensions.data();


    VkInstance instance;
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }

    return instance;
}

bool checkVKApiVersion(uint32_t targetVersion) {
    auto fnVkEnumerateInstanceVersion = PFN_vkEnumerateInstanceVersion(vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceVersion"));
    if (fnVkEnumerateInstanceVersion == nullptr) {
        return false;
    }

    uint32_t currentVersion;
    fnVkEnumerateInstanceVersion(&currentVersion);

    return currentVersion >= targetVersion;
}

KNN_NAMESPACE_END
