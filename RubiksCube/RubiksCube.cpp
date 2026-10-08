#include <iostream>
#include <glm/glm.hpp>
#include <stb_image.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
    glm::vec3 my_vec = glm::vec3(1.0f,1.0f,1.0f);
    for (int i = 0; i < 10;i++)
    {
        std::cout << "Hello World!\n";
    }

    glfwInit();
    glewInit();
}
