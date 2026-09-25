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
		
		-0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 0.0f,
		 0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 1.0f

	};

	GLuint indeces [] = {
		0, 2, 6,
		2, 4, 6
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

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glUseProgram(shaderProgram);
	 
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window)) {
		
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT);

		float timeValue {static_cast<float>(glfwGetTime())};
		float greenValue {(sin(timeValue) + 1.0f) / 2.0f};
		float blueValue {(sin(timeValue + 4.0f) + 1.0f) / 2.0f};
		float redValue = {(sin(timeValue + 2.0f) + 1.0f) / 2.0f};
		int vertexColorLocation {glGetUniformLocation(shaderProgram, "vertexChangeColor")}; 
		glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);
		
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawElements(GL_LINE_LOOP, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glDeleteProgram(shaderProgram);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);

	return 0;
}