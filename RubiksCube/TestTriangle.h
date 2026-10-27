#pragma once

#include "GameInterface.h"

#include <GL/glew.h>

class TestTriangle : public GameInterface
{
public:
    void Initialize() override;
    void Update(double deltaTime) override;;
    void Render(float aspectRatio) override;
    void ClearResources() override;

private:
    float m_turningAngle;
};
