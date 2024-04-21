//
// Created by keen on 4/8/24.
//

#ifndef KEEN_VULKAN_DEVICE_H
#define KEEN_VULKAN_DEVICE_H

#include <vulkan/vulkan.h>
#include <stdexcept>
#include <vector>

KNN_NAMESPACE_BEGIN

VkDevice createLogicalDevice(const VkInstance &instance);

std::vector<VkPhysicalDevice> getPhysicalDevices(const VkInstance &instance);

VkPhysicalDevice pickSuitableDevice(const std::vector<VkPhysicalDevice> &devices);

std::vector<VkQueueFamilyProperties> getPhysicalDeviceQueueFamilies(const VkPhysicalDevice &device);

VkQueueFlagBits getDesiredQueueAbilities();

KNN_NAMESPACE_END

#endif //KEEN_VULKAN_DEVICE_H
