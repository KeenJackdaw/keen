//
// Created by keen on 4/4/24.
//

#include "kernel/model.h"

KNN_NAMESPACE_BEGIN

knn::Model::Model(knm::Vec3 w_loc, knm::Vec3 w_vec, knm::Vec3 l_loc, knm::Vec3 l_vec) :
w_loc(w_loc), w_vec(w_vec), l_loc(l_loc), l_vec(l_vec) {}

knn::Model::Model(knm::Vec3 w_loc, knm::Vec3 w_vec) :
Model(w_loc, w_vec, knm::Vec3::zero(), knm::Vec3::zero()){}

knn::Model::Model() :
Model(knm::Vec3::zero(), knm::Vec3::zero()){}

const knm::Vec3 &Model::getLoc(CoordType type) const {
    if (type == CoordType::LOCAL) {
        return this->l_loc;
    }
    return this->w_loc;
}

const knm::Vec3 &Model::getVec(CoordType type) const {
    if (type == CoordType::LOCAL) {
        return this->l_vec;
    }
    return this->w_vec;
}

KNN_NAMESPACE_END