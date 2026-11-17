#include "InputSystem.h"

#include <iostream>
#include <ostream>
#include <GLFW/glfw3.h>
#include <glm/ext/quaternion_geometric.hpp>

void InputSystem::ObserveKey(int key)
{
    m_keyMapper[key] = KeyObserver(m_window, key);
}

void InputSystem::Update()
{
    for (auto& pair : m_keyMapper)
    {
        pair.second.Update();
    }
}

bool InputSystem::IsLeftMouseButtonDown()
{
    return glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
}

bool InputSystem::IsRightMouseButtonDown()
{
    return glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
}

void InputSystem::GetMousePosition(double& xPos, double& yPos)
{
    glfwGetCursorPos(m_window, &xPos, &yPos);

    int windowX, windowY;
    glfwGetFramebufferSize(m_window, &windowX, &windowY);

    double xClipPos, yClipPos;
    xClipPos = (xPos / static_cast<double>(windowX - 1) - 0.5) * 2.0;
    yClipPos = -(yPos / static_cast<double>(windowY - 1) - 0.5) * 2.0;

    std::cout << "ScreenCoordinates : (" << xPos << ", " << yPos << ")\n";
    std::cout << "ClipCoordinates   : (" << xClipPos << ", " << yClipPos << ")\n";

    xPos = xClipPos;
    yPos = yClipPos;
}

void InputSystem::GetPickingRay(const glm::mat4& transformationMatrix, glm::vec3& startingPoint,
                                glm::vec3& direction)
{
    double xClip, yClip;
    GetMousePosition(xClip, yClip);

    auto nearPoint = glm::vec4(static_cast<float>(xClip), static_cast<float>(yClip), -0.999f, 1.0f);
    auto farPoint = nearPoint;
    farPoint.z *= -1.0f;

    glm::mat4 inverse = glm::inverse(transformationMatrix);

    nearPoint = inverse * nearPoint;
    farPoint = inverse * farPoint;

    nearPoint = nearPoint / nearPoint.w;
    farPoint = farPoint / farPoint.w;

    startingPoint = nearPoint;
    direction = farPoint - nearPoint;

    direction = glm::normalize(direction);
}
