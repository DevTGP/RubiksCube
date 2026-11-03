#include "CubieRenderer.h"

#include <cassert>


void CubieRenderer::Initialize()
{
    float floatArray[6 * 6 * 3];
    std::vector<glm::vec3> positionField;
    std::vector<glm::vec3> colorField;

    for (int sideType = 0; sideType < 3; ++sideType)
    {
        for (int direction : {-1, 1}) { AddSidePosition(sideType, direction, positionField); }
    }

    TranscribeToFloatArray(positionField, floatArray);
}

void CubieRenderer::AddSidePosition(int sideType, int direction, std::vector<glm::vec3>& positionArray)
{
    assert(sideType >= 0 && sideType <= 2);
    glm::vec3 cornerPoints[2][2];

    const int localXDim = (sideType + 1) % 3;
    const int localYDim = (sideType + 2) % 3;

    for (const int i : {0, 1})
    {
        for (const int j : {0, 1})
        {
            glm::vec3 localPoint(static_cast<float>(direction) * m_offset);
            localPoint[localXDim] = (2.0f * static_cast<float>(i) - 1.0f) * m_offset;
            localPoint[localYDim] = (2.0f * static_cast<float>(j) - 1.0f) * m_offset;
            cornerPoints[i][j] = localPoint;
        }
    }

    positionArray.push_back(cornerPoints[0][0]);
    positionArray.push_back(cornerPoints[0][1]);
    positionArray.push_back(cornerPoints[1][0]);

    positionArray.push_back(cornerPoints[1][1]);
    positionArray.push_back(cornerPoints[0][1]);
    positionArray.push_back(cornerPoints[1][0]);
}

void CubieRenderer::TranscribeToFloatArray(const std::vector<glm::vec3>& vecArray, float* floatArray)
{
    int writingCounter = 0;
    for (int i = 0; i < 26; ++i)
    {
        for (const int coord : {0, 1, 2,}) { floatArray[writingCounter++] = vecArray[i][coord]; }
    }
}
