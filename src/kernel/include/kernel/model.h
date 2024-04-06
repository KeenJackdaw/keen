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
    knm::Vec3 l_loc;
    knm::Vec3 l_vec;

    knm::Vec3 w_loc;
    knm::Vec3 w_vec;

public:
    Model(knm::Vec3 w_loc, knm::Vec3 w_vec, knm::Vec3 l_loc, knm::Vec3 l_vec);
    Model(knm::Vec3 w_loc, knm::Vec3 w_vec);
    Model();

    ~Model() = default;

    [[nodiscard]] const knm::Vec3 &getLoc(CoordType type) const;
    [[nodiscard]] const knm::Vec3 &getVec(CoordType type) const;
};

KNN_NAMESPACE_END

#endif //KEEN_MODEL_H
