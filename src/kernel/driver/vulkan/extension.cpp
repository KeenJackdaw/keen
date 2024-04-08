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

KNN_NAMESPACE_END


