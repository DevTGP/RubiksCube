#pragma once

#include "GameInterface.h"
#include <GL/glew.h>

class TestCubie : public GameInterface
{
public:
    void Initialize() override;
    // void Initialize(GLFWwindow* window) override;
    // void Update(double deltaTime) override;
    // void Render(float aspectRatio) override;
    void ClearResources() override;

private:
    GLuint m_shaderProgram;
};
