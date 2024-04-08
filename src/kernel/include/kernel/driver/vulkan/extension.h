//
// Created by keen on 4/8/24.
//

#ifndef KEEN_EXTENSION_H
#define KEEN_EXTENSION_H

#include <vulkan/vulkan.h>
#include <vector>
#include <GLFW/glfw3.h>

KNN_NAMESPACE_BEGIN

/**
 * must be invoked after glfw window initialization
 * @return
 */
std::vector<const char *> getGLFWExtensions();

std::vector<const char *> getValidationExtensions();

KNN_NAMESPACE_END

#endif //KEEN_EXTENSION_H
