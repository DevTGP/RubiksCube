#pragma once

#include "CubieRenderer.h"
#include "GameInterface.h"
#include "InputSystem.h"
#include <glm/ext/quaternion_float.hpp>


class TestKey : public GameInterface
{
public:
    void Initialize(GLFWwindow* window) override;
    void Update(double deltaTime) override;
    void ClearResources() override;
    void Render(float aspectRatio) override;

private:
    InputSystem m_input;
    CubieRenderer m_cubieRenderer;
    glm::quat m_orientationQuaternion;
};
