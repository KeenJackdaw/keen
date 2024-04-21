//
// Created by keen on 4/8/24.
//

#include "kernel/driver/vulkan/device.h"

KNN_NAMESPACE_BEGIN

VkDevice createLogicalDevice(const VkInstance &instance, const VkPhysicalDevice &physicalDevice, const std::vector<VkQueueFamilyProperties> &queueFamilies) {
    if (queueFamilies.empty()) {
        throw std::runtime_error("empty device queue family");
    }

    VkQueueFlagBits desiredQueueAbilities = knn::getDesiredQueueAbilities();

    int desiredQueueFamilyIndex = -1;
    for (int i = 0; i < queueFamilies.size(); i++) {
        VkQueueFamilyProperties queueFamily = queueFamilies[i];
        if (0 != queueFamily.queueCount && (queueFamily.queueFlags & desiredQueueAbilities)) {
            desiredQueueFamilyIndex = i;
            break;
        }
    }

    if (-1 == desiredQueueFamilyIndex) {
        throw std::runtime_error("no desired queue family found");
    }

    VkDeviceCreateInfo createInfo{};


}

std::vector<VkPhysicalDevice> getPhysicalDevices(const VkInstance &instance) {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

    if (0 == deviceCount) {
        throw std::runtime_error("failed to find physical device with vulkan support");
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

    return devices;
}

VkPhysicalDevice pickSuitableDevice(const std::vector<VkPhysicalDevice> &devices) {
    if (devices.empty()) {
        return nullptr;
    }

    return devices.at(0);
}

std::vector<VkQueueFamilyProperties> getPhysicalDeviceQueueFamilies(const VkPhysicalDevice &device) {
    uint32_t queueCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueCount, nullptr);

    if (0 == queueCount) {
        return {};
    }

    std::vector<VkQueueFamilyProperties> queueFamilyProperties(queueCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueCount, queueFamilyProperties.data());

    return queueFamilyProperties;
}

VkQueueFlagBits getDesiredQueueAbilities() {
    VK_QUEUE_GRAPHICS_BIT;
}

KNN_NAMESPACE_END
