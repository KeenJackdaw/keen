//
// Created by keen on 4/4/24.
//

#include "kernel/model.h"

KNN_NAMESPACE_BEGIN

knn::Model::Model(knm::Vec3 worldPosition, knm::Vec3 worldDirection, knm::Vec3 localPosition, knm::Vec3 localDirection) :
        worldPosition(worldPosition), worldDirection(worldDirection), localPosition(localPosition), localDirection(localDirection) {}

knn::Model::Model(knm::Vec3 worldPosition, knm::Vec3 worldDirection) :
Model(worldPosition, worldDirection, knm::Vec3::zero(), knm::Vec3::zero()){}

knn::Model::Model() :
Model(knm::Vec3::zero(), knm::Vec3::zero()){}

const knm::Vec3 &Model::getPosition(CoordType type) const {
    if (type == CoordType::LOCAL) {
        return this->localPosition;
    }
    return this->worldPosition;
}

const knm::Vec3 &Model::getDirection(CoordType type) const {
    if (type == CoordType::LOCAL) {
        return this->localDirection;
    }
    return this->worldDirection;
}

KNN_NAMESPACE_END