//
// Created by keen on 4/6/24.
//

#ifndef KEEN_VALIDATION_H
#define KEEN_VALIDATION_H

#include <vulkan/vulkan.h>
#include <vector>
#include <cstring>

#define KNN_VK_VALIDATION_LAYER "VK_LAYER_KHRONOS_validation"

KNN_NAMESPACE_BEGIN

bool supportValidation();

KNN_NAMESPACE_END

#endif //KEEN_VALIDATION_H
