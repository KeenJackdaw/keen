//
// Created by keen on 4/4/24.
//

#include "math/linear/vec3.h"

KNM_NAMESPACE_BEGIN

knm::Vec3 transform(knm::Vec3 location, knm::Vec3 distance) {
    return {
        location.x + distance.x,
        location.y + distance.y,
        location.z + distance.z
    };
}

knm::Vec3 transform(knm::Vec3 location, float dx, float dy, float dz) {
    return knm::transform(location, {dx, dy, dz});
}

knm::Vec3 normalize(knm::Vec3 direction) {
    float sum = 0.0;

    sum += direction.x * direction.x;
    sum += direction.y * direction.y;
    sum += direction.z * direction.z;

    float length = sqrtf(sum);

    return {direction.x / length, direction.y / length, direction.z / length};
}

KNM_NAMESPACE_END