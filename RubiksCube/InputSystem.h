#pragma once
#include "KeyObserver.h"
#include <map>
#include <glm/mat4x4.hpp>

class InputSystem
{
public:
    InputSystem()
    {
        m_window = nullptr;
    }

    void setWindow(GLFWwindow* window)
    {
        m_window = window;
    }

    void ObserveKey(int key);
    void Update();

    bool IsDown(int key)
    {
        return m_keyMapper.at(key).IsDown();
    }

    bool IsPressed(int key)
    {
        return m_keyMapper.at(key).IsPressed();
    }

    bool IsReleased(int key)
    {
        return m_keyMapper.at(key).IsReleased();
    }

    bool IsLeftMouseButtonDown();
    bool IsRightMouseButtonDown();

    void GetMousePosition(double& xPos, double& yPos);

    void GetPickingRay(const glm::mat4& transformationMatrix, glm::vec3& startingPoint, glm::vec3& direction);

private:
    GLFWwindow* m_window;
    std::map<int, KeyObserver> m_keyMapper;
};
