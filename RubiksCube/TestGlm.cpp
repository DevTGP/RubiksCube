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

    float* mat_pointer = glm::value_ptr(diff);

    glm::mat4 test = glm::lookAt(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f),
                                 glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 object_view = test * alternate_compound;

    glm::mat4 view_to_clip = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 10.0f);

    auto test_vec = glm::vec4(1.0f, 2.0f, 3.0f, 1.0f);
    glm::vec4 first_trans = object_view * test_vec;

    glm::vec4 complete_trans = view_to_clip * object_view * test_vec;


    int blub = 1;

    m_orientationQuaternion = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
}

void TestGlm::Update(double deltaTime)
{
    GameInterface::Update(deltaTime);

    auto rotation_velocity = glm::quat(0.0f, glm::radians(180.0f), 0.0f, 0.0f);
    glm::quat time_derivative = 0.5f * rotation_velocity * m_orientationQuaternion;

    m_orientationQuaternion += time_derivative * static_cast<const float>(deltaTime);
    m_orientationQuaternion = glm::normalize(m_orientationQuaternion);

    float test_length = glm::length(m_orientationQuaternion);

    glm::mat4 final_rotation = glm::mat4_cast(m_orientationQuaternion);


    int blib = 1;
}

void TestGlm::Render(float aspectRatio)
{
    glm::mat4 complete =
        glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 10.0f)
        * glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f))
        * glm::mat4_cast(m_orientationQuaternion);

    float* pointer = glm::value_ptr(complete);
}
