//
// Created by app on 3/31/24.
//

#ifndef KEEN_VEC3_H
#define KEEN_VEC3_H

#include <cmath>

KNM_NAMESPACE_BEGIN

struct Vec3 {
    float x;
    float y;
    float z;

    static Vec3 zero() {
        return {0.0f, 0.0f, 0.0f};
    }
};

static knm::Vec3 transform(knm::Vec3 location, knm::Vec3 distance);
static knm::Vec3 transform(knm::Vec3 location, float dx, float dy, float dz);
static knm::Vec3 normalize(knm::Vec3 direction);

KNM_NAMESPACE_END

#endif //KEEN_VEC3_H
