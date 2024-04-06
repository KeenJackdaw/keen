//
// Created by app on 3/9/24.
//

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "HelloTriangleApplication.h"

int main() {
    HelloTriangleApplication app;
    int result = EXIT_SUCCESS;
    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        result = EXIT_FAILURE;
    }
    return result;
}