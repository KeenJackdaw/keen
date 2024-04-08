//
// Created by keen on 4/6/24.
//

#include "device/gpu/gpu.h"
#include "kernel/driver/vulkan/validation.h"

KND_NAMESPACE_BEGIN

GPUDevice::GPUDevice(knd::DeviceInfo *deviceInfo) {
    this->supportValidationLayer = knn::supportValidation();

    if (this->supportValidationLayer) {

    }
}

KND_NAMESPACE_END