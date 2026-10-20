#pragma once
#include <glm/ext/quaternion_float.hpp>


#include "GameInterface.h"

class TestGlm : public GameInterface
{
public:
    void Initialize() override;

    void Update(double deltaTime) override;
    void Render(float aspectRatio) override;

private:
    glm::quat m_orientationQuaternion;
};
