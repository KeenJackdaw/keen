//
// Created by keen on 4/6/24.
//

#ifndef KEEN_VULKAN_VALIDATION_H
#define KEEN_VULKAN_VALIDATION_H

#include <iostream>
#include <vulkan/vulkan.h>
#include <vector>
#include <cstring>

#define KNN_VK_VALIDATION_LAYER "VK_LAYER_KHRONOS_validation"

KNN_NAMESPACE_BEGIN

bool supportValidation();

VkBool32 debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                       VkDebugUtilsMessageTypeFlagsEXT messageType,
                       const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
                       void *pUserData);

VkDebugUtilsMessengerCreateInfoEXT populateDebugMessengerCreateInfo();

std::vector<const char *> getValidationLayers();

KNN_NAMESPACE_END

#endif //KEEN_VULKAN_VALIDATION_H
