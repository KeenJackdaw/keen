//
// Created by keen on 4/7/24.
//

#include "kernel/driver/vulkan/application.h"

KNN_NAMESPACE_BEGIN

VkInstance createVKInstance(uint32_t apiVersion) {
    VkApplicationInfo appInfo{};

    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = KEEN;
    appInfo.applicationVersion = KNN_MAKE_VERSION(KEEN_VERSION_MAJOR, KEEN_VERSION_MINOR, KEEN_VERSION_PATCH);
    appInfo.pEngineName = KEEN_ENGINE;

    if (!checkVKApiVersion(apiVersion)) {
        throw std::runtime_error("apiVersion requirement check failed");
    }

    appInfo.apiVersion = apiVersion;

    appInfo.pNext = nullptr;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    VkDebugUtilsMessengerCreateInfoEXT createInfoExt = populateDebugMessengerCreateInfo();

    std::vector<const char *> layers = getValidationLayers();
    createInfo.enabledLayerCount = layers.size();
    createInfo.ppEnabledLayerNames = layers.empty() ? nullptr : layers.data();
    createInfo.pNext = &createInfoExt;

    std::vector<const char *> extensions = getInstanceExtensions();
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
