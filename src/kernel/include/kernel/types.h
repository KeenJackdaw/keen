//
// Created by keen on 4/4/24.
//

#ifndef KEEN_TYPES_H
#define KEEN_TYPES_H

#define KNN_MAKE_VERSION(major, minor, patch) \
    ((uint32_t) major << 20U) | ((uint32_t) minor << 10U) | ((uint32_t) patch << 2U)

KNN_NAMESPACE_BEGIN

typedef enum CoordType {
    WORLD = 0x01,
    LOCAL = 0x02
} CoordType;

KNN_NAMESPACE_END

#endif //KEEN_TYPES_H
