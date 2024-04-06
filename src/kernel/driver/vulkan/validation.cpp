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

KNN_NAMESPACE_END