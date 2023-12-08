#include <iostream>
#include <string>

#include "Window.h"
#include "Renderer.h"
#include "Model.h"
#include "Shader.h"
#include "Texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;



int main()
{

    Window  window("Vjezba4", SCR_WIDTH, SCR_HEIGHT);
  
    Model   model("res/objects/all.obj");
    Model   dragon("res/objects/dragon.obj");

    Shader  shader("res/shaders/vShader.glsl", "res/shaders/fShader.glsl");
    Texture tex("res/textures/container.jpg");

    Renderer render;



    while (!window.isClosed())
    {
        glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.5f, 0.5f, 0.0f));


        glm::mat4 rot = glm::mat4(1.0f);
        rot = glm::rotate(rot, (float)glfwGetTime() * glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));

        glm::mat4 scal = glm::mat4(1.0f);
        scal = glm::scale(scal, glm::vec3(0.5, 0.5, 0.5));


        window.ProcessInput();
        render.Clear();


        shader.SetUniform4x4("model", rot);
        shader.SetUniform4x4("view", trans);
        shader.SetUniform4x4("projection", scal);
        model.Draw(shader, tex);

        shader.SetUniform4x4("model", trans);
        dragon.Draw(shader, tex);

        window.SwapAndPoll();
    }

    window.CloseWindow();

    return 0;
}