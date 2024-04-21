//
// Created by keen on 4/7/24.
//

#ifndef KEEN_VULKAN_APPLICATION_H
#define KEEN_VULKAN_APPLICATION_H

#include <algorithm>
#include <vulkan/vulkan.h>
#include "kernel/driver/vulkan/validation.h"
#include "kernel/driver/vulkan/extension.h"
#include "kernel/types.h"

KNN_NAMESPACE_BEGIN

VkInstance createVKInstance(uint32_t apiVersion);

bool checkVKApiVersion(uint32_t targetVersion);

KNN_NAMESPACE_END

#endif //KEEN_VULKAN_APPLICATION_H
