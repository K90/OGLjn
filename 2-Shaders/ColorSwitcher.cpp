#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>


void applyDynamicColoring(int shaderProgram) {

	float timeValue {static_cast<float>(glfwGetTime())};
	float red {(sin(timeValue * 1.0f + 4) + 1) / 2};
	float green {(sin(timeValue * 1.0f) + 1) / 2};
	float blue {(sin(timeValue * 1.0f + 2)  + 1) / 2};

	int vertexChangeColorLocation {glGetUniformLocation(shaderProgram, "vertexChangeColor")}; 
	glUniform4f(vertexChangeColorLocation, red, green, blue, 1.0f);

}

void resetColorToDefault(int shaderProgram) {

	float red{};
	float green {};
	float blue {};

	int vertexChangeColorLocation {glGetUniformLocation(shaderProgram, "vertexChangeColor")};
	glUniform4f(vertexChangeColorLocation, red, green, blue, 1.0f);

}