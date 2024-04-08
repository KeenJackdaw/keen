//
// Created by app on 3/9/24.
//

#include <iostream>
#include "kernel/driver/vulkan/application.h"
int main() {

    VkInstance instance = knn::createVKInstance("keen", "keen", 1, VK_API_VERSION_1_1);
    std::cout << "Hello world" << std::endl;
}