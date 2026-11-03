#include "TestCubie.h"
#include "ShaderUtil.h"

void TestCubie::Initialize() { m_shaderProgram = ShaderUtil::CreateShaderProgram("VColor.glsl", "FColor.glsl"); }


void TestCubie::ClearResources()
{
    glDeleteProgram(m_shaderProgram);
}
