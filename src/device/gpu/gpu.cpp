//
// Created by keen on 4/6/24.
//

#include "device/gpu/gpu.h"
#include "kernel/driver/vulkan/application.h"
#include "kernel/driver/vulkan/device.h"

KND_NAMESPACE_BEGIN

GPUDevice::GPUDevice(knd::DeviceInfo *deviceInfo) {
    this->supportValidation = knn::supportValidation();
    this->instance = knn::createVKInstance(VK_API_VERSION_1_1);
    this->physicalDevices = knn::getPhysicalDevices(this->instance);
    this->physicalDevice = knn::pickSuitableDevice(this->physicalDevices);
    this->queueFamilies = knn::getPhysicalDeviceQueueFamilies(this->physicalDevice);
}

KND_NAMESPACE_END