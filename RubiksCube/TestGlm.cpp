#include "TestGlm.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

void TestGlm::Initialize()
{
    int i = 1;

    auto first_vector = glm::vec3(1.0f, 2.0f, 3.0f);
    auto second_vector = glm::vec4(first_vector, 1.0f);

    first_vector = glm::normalize(first_vector);
    float inner = glm::dot(first_vector, first_vector);

    float* pointer = glm::value_ptr(first_vector);

    auto first_mat = glm::mat4(1.0f);
    glm::vec4 transform = first_mat * second_vector;

    glm::mat4 trans = glm::translate(glm::identity<glm::mat4>(), first_vector);
    glm::vec4 second_trans = trans * second_vector;
    glm::mat4 rotate = glm::rotate(glm::identity<glm::mat4>(), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 compound = trans * rotate; // erst verdrehen, dann verschieben

    glm::mat4 alternate_compound = glm::rotate(trans, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 diff = alternate_compound - compound;


    int blub = 1;
}
