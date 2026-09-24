#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "window.h"
#include "shaders.h"
		
int main(void) {

	GLFWwindow* window {createWindow()};
	getOpenGLInfo();

	GLuint vertexShader {initVertexShader()};
	GLuint fragmentShader {initFragmentShader()};
	GLuint shaderProgram {initShaderProgram(vertexShader, fragmentShader)};
	testAndClean(vertexShader, fragmentShader, shaderProgram);

	float vertices [] = {
		
		-0.5f,  0.5f,  0.0f,
		 0.5f,  0.5f,  0.0f,
		 0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f

	};

	GLuint indeces [] = {
		0, 1, 3,
		1, 2, 3
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	float timeValue = glfwGetTime();
	int vertexColorLocation = glGetUniformLocation(shaderProgram, "vertexColor"); 
	glUseProgram(shaderProgram);
	glUniform4f(vertexColorLocation, 0.0f, 1.0f, 0.0f, 1.0f);

	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window)) {
		
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT);
		
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawElements(GL_LINE_LOOP, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glDeleteProgram(shaderProgram);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);

	return 0;
}