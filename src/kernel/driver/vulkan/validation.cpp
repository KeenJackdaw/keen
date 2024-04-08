//
// Created by keen on 4/6/24.
//

#include "kernel/driver/vulkan/validation.h"

KNN_NAMESPACE_BEGIN

bool supportValidation() {
    uint32_t layerCount = 0;
    if (VK_SUCCESS != vkEnumerateInstanceLayerProperties(&layerCount, nullptr)) {
        return false;
    }

    std::vector<VkLayerProperties> availableLayers(layerCount);
    if (VK_SUCCESS != vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data())) {
        return false;
    }

    for (const auto &layer: availableLayers) {
        if (0 == strcmp(layer.layerName, KNN_VK_VALIDATION_LAYER)) {
            return true;
        }
    }

    return false;
}

std::vector<const char *> getValidationLayers() {
    return {KNN_VK_VALIDATION_LAYER};
}

VkBool32
debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType,
              const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData, void *pUserData) {
    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

    return VK_FALSE;
}

VkDebugUtilsMessengerCreateInfoEXT populateDebugMessengerCreateInfo() {
    VkDebugUtilsMessengerCreateInfoEXT createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    createInfo.pfnUserCallback = debugCallback;

    return createInfo;
}

KNN_NAMESPACE_END