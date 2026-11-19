#pragma once
#include "CubieRenderer.h"
#include "GameInterface.h"
#include "InputSystem.h"

class TestMouse : public GameInterface
{
public:
    void Initialize(GLFWwindow* window) override;
    void Update(double deltaTime) override;
    void Render(float aspectRatio) override;
    void ClearResources() override;

private:
    InputSystem m_inputSystem;
    CubieRenderer m_renderer;
    glm::vec3 m_cubiePosition;
    glm::mat4 m_viewProjectionMatrix;
};
