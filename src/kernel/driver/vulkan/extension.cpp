//
// Created by keen on 4/8/24.
//

#include "kernel/driver/vulkan/extension.h"

KNN_NAMESPACE_BEGIN

std::vector<const char *> getGLFWExtensions() {
    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    if (nullptr == glfwExtensions) {
        return {};
    }

    return {glfwExtensions, glfwExtensions + glfwExtensionCount};
}

std::vector<const char *> getValidationExtensions() {
    return {VK_EXT_DEBUG_UTILS_EXTENSION_NAME};
}

std::vector<const char *> getInstanceExtensions() {
    std::vector<const char *> glfwExtensions = getGLFWExtensions();
    std::vector<const char *> validationExtensions = getValidationExtensions();
    std::vector<const char *> extensions(glfwExtensions.size() + validationExtensions.size());
    std::merge(glfwExtensions.begin(), glfwExtensions.end(), validationExtensions.begin(), validationExtensions.end(), extensions.begin());

    return extensions;
}

std::vector<const char *> getDeviceExtensions() {
    return {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
}

KNN_NAMESPACE_END


