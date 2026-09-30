#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

#include "ShaderProgram.h"
#include "Window.h"

int main() {
	
	GLFWwindow* window {createWindow()};

	ShaderProgram triangleShader("res/shaders/triangle.vert", "res/shaders/triangle.frag");

	float vertices[] {

		-0.5f, -0.5f,  0.0f,
		 0.0f,  0.5f,  0.0f,
		 0.5f, -0.5f,  0.0f

	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	triangleShader.use();

	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window)) {
	
		handleInput(window);
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();
	return 0;
}

