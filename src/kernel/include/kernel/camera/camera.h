//
// Created by app on 3/31/24.
//

#ifndef KEEN_CAMERA_H
#define KEEN_CAMERA_H

#include <cmath>
#include "kernel/model.h"

KNN_NAMESPACE_BEGIN

/**
 *              up
 *              |
 *              |
 *              |
 *              |
 *         __ /_/\___
 *        /__/[]\/__/|
 *       |    _     ||
 *       |  ((_))   ||
 *       |__________|/
 *          /
 *         /
 *        /
 *       /
 *    look at
 */

    class Camera: Model {
    private:
        // fov
        float fov;

        // far plane and near plane
        float far;
        float near;

    public:
        // constructor
        Camera(knm::Vec3 loc, knm::Vec3 vec, float fov, float far, float near);
        Camera(float fov, float far, float near);

        // destructor
        ~Camera() = default;

        // move
        virtual void transform(knm::Vec3 distance);
        virtual void transform(double dx, double dy, double dz);

        // look at
        virtual void lookAt(knm::Vec3 loc);
    };

}

#endif //KEEN_CAMERA_H
