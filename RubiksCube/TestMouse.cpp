#include "TestMouse.h"

#include <iostream>
#include <GLFW/glfw3.h>

void TestMouse::Initialize(GLFWwindow* window)
{
    m_inputSystem.setWindow(window);
    m_wasMousePressed = false;
    m_window = window;
}

void TestMouse::Update(double deltaTime)
{
    bool isPressed = m_inputSystem.IsLeftMouseButtonDown();
    if (isPressed && !m_wasMousePressed)
    {
        double xPos, yPos;
        m_inputSystem.GetMousePosition(xPos, yPos);
    }
    m_wasMousePressed = isPressed;
}

void TestMouse::Render(float aspectRatio) {}

void TestMouse::ClearResources() {}
