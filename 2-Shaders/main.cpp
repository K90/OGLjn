#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "window.h"

const char *vertexShaderSource =	"#version 330 core\n"
									"layout (location = 0) in vec3 aPos\n"
									"void main() {\n"
									"	gl_position = vec3(aPos.x, aPos.y, aPos.z, 1.0);\n"
									"}\0";

int main(void)
{
	GLFWwindow* window = createWindow();

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	float vertices [] = {

		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//copy data into the currently bound buffer (VBO)


	while (!glfwWindowShouldClose(window)) {
		
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
}