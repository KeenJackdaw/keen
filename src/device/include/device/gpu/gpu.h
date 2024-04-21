//
// Created by keen on 4/6/24.
//

#ifndef KEEN_GPU_H
#define KEEN_GPU_H

#include <vulkan/vulkan.h>
#include "device/device.h"
#include "device/deviceinfo.h"

KND_NAMESPACE_BEGIN

class GPUDevice : Device {
private:
    // validation related
    bool supportValidation = false;

    // device related
    std::vector<VkPhysicalDevice> physicalDevices{};
    VkPhysicalDevice physicalDevice = nullptr;
    std::vector<VkQueueFamilyProperties> queueFamilies{};
    VkDevice vkDevice = nullptr;

    // vulkan instance
    VkInstance instance = nullptr;

public:
    explicit GPUDevice(DeviceInfo *deviceInfo);

};

KND_NAMESPACE_END

#endif //KEEN_GPU_H
