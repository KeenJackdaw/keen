//
// Created by keen on 4/7/24.
//

#ifndef KEEN_VULKAN_APPLICATION_H
#define KEEN_VULKAN_APPLICATION_H

#include <algorithm>
#include <vulkan/vulkan.h>
#include "validation.h"
#include "extension.h"

KNN_NAMESPACE_BEGIN

VkInstance createVKInstance(const char *appName, const char *engineName, uint32_t appVersion, uint32_t apiVersion);

bool checkVKApiVersion(uint32_t targetVersion);

KNN_NAMESPACE_END

#endif //KEEN_VULKAN_APPLICATION_H
