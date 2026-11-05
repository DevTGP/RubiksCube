#pragma once

#include "GameInterface.h"

#include "CubieRenderer.h"

class TestCubie : public GameInterface
{
public:
    void Initialize() override;
    void Update(double deltaTime) override;
    void Render(float aspectRatio) override;
    void ClearResources() override;

private:
    CubieRenderer m_cubieRenderer;
    float m_turningAngle;
};
