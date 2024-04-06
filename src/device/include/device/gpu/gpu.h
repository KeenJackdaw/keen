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
    VkPhysicalDevice physicalDevice = nullptr;
    VkDevice vkDevice = nullptr;
    VkInstance instance = nullptr;

public:
    explicit GPUDevice(DeviceInfo *deviceInfo);

};

KND_NAMESPACE_END

#endif //KEEN_GPU_H
