//
// Created by app on 3/31/24.
//

#include "kernel/camera/camera.h"

KNN_NAMESPACE_BEGIN

Camera::Camera(knm::Vec3 loc, knm::Vec3 vec, float fov, float far, float near) :
        Model(loc, vec), fov(fov), far(far), near(near) {}

Camera::Camera(float fov, float far, float near) :
        Model(knm::Vec3::zero(), knm::Vec3::zero()), fov(fov), far(far), near(near) {}

void Camera::transform(knm::Vec3 distance) {

}

void Camera::transform(double dx, double dy, double dz) {

}

void Camera::lookAt(knm::Vec3 loc) {

}

KNN_NAMESPACE_END




