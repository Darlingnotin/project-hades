//
//  JointRayPick.h
//  interface/src/raypick
//
//  Created by Sam Gondelman 7/11/2017
//  Copyright 2017 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//
#ifndef hifi_JointRayPick_h
#define hifi_JointRayPick_h

#include "RayPick.h"

#include <QString>

class JointRayPick : public RayPick {

public:
    JointRayPick(const QString& jointName, const glm::vec3& posOffset, const glm::vec3& dirOffset, const uint16_t filter, const float maxDistance = 0.0f, const bool enabled = false);

    const PickRay getPickRay(bool& valid) override;

private:
    QString _jointName;
    glm::vec3 _posOffset;
    glm::vec3 _dirOffset;

};

#endif // hifi_JointRayPick_h
