#pragma once
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
    bool m_wasMousePressed;
    GLFWwindow* m_window;
};
