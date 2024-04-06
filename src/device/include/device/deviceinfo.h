//
// Created by keen on 4/6/24.
//

#ifndef KEEN_DEVICEINFO_H
#define KEEN_DEVICEINFO_H

#include <vulkan/vulkan.h>

KND_NAMESPACE_BEGIN

class DeviceInfo {
public:
    bool useHardware = false;

public:
    DeviceInfo() = default;

    [[nodiscard]] bool isUseHardware() const { return this->useHardware; }
};

KND_NAMESPACE_END

#endif //KEEN_DEVICEINFO_H
