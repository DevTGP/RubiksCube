#include "TestMouse.h"

#include <GLFW/glfw3.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

void TestMouse::Initialize(GLFWwindow* window)
{
    m_inputSystem.setWindow(window);
    m_renderer.Initialize();
    m_viewProjectionMatrix = glm::mat4(1.0f);
    m_cubiePosition = glm::vec3(0.0f);
}

void TestMouse::Update(double deltaTime)
{
    if (!m_inputSystem.IsLeftMouseButtonDown())
        return;

    glm::vec3 position, direction;
    m_inputSystem.GetPickingRay(m_viewProjectionMatrix, position, direction);
    m_cubiePosition = position + direction * (9.0f - 0.01f);
}

void TestMouse::Render(float aspectRatio)
{
    m_viewProjectionMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, 0.01f, 100.0f)
        * glm::lookAt(glm::vec3(0.0f, 0.0f, -9.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 objectToClip = glm::translate(m_viewProjectionMatrix, m_cubiePosition);

    m_renderer.Render(objectToClip);
}

void TestMouse::ClearResources()
{
    m_renderer.ClearResources();
}
