//
// Created by keen on 4/4/24.
//

#ifndef KEEN_MODEL_H
#define KEEN_MODEL_H

#include "types.h"
#include "math/linear/vec3.h"

KNN_NAMESPACE_BEGIN

class Model {
private:
    knm::Vec3 localPosition;
    knm::Vec3 localDirection;

    knm::Vec3 worldPosition;
    knm::Vec3 worldDirection;

public:
    Model(knm::Vec3 worldPosition, knm::Vec3 worldDirection, knm::Vec3 localPosition, knm::Vec3 localDirection);
    Model(knm::Vec3 worldPosition, knm::Vec3 worldDirection);
    Model();

    ~Model() = default;

    [[nodiscard]] const knm::Vec3 &getPosition(CoordType type) const;
    [[nodiscard]] const knm::Vec3 &getDirection(CoordType type) const;
};

KNN_NAMESPACE_END

#endif //KEEN_MODEL_H
