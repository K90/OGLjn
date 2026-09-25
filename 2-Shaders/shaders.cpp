#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "shaders.h"

const char *vertexShaderSource = "#version 330 core\n"
								 "layout (location = 0) in vec3 aPos;\n"
								 "layout (location = 1) in vec3 aColor;\n"
								 "out vec3 vertexColor;\n"
								 "void main() {\n"
								 "	  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
								 "	  vertexColor = aColor;\n"
								 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
								   "uniform vec4 vertexChangeColor;\n"
								   "out vec4 FinalColor;\n"
								   "vec4 FragColor;\n"
								   "in vec3 vertexColor;\n"
								   "void main() {\n"
								   "	FragColor = vec4(vertexColor, 1.0);\n"
								   "	FinalColor = FragColor + vertexChangeColor;\n"
								   "}\0";
GLuint initVertexShader() {
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	return vertexShader;
}

GLuint initFragmentShader() {

	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	return fragmentShader;
}



GLuint initShaderProgram(GLuint vert, GLuint frag) {

	GLuint shaderProgram;	
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vert);
	glAttachShader(shaderProgram, frag);
	glLinkProgram(shaderProgram);

	return shaderProgram;
};

void testAndClean(GLuint vert, GLuint frag, GLuint program) {
	int success;
	char infoLog[512];

	glGetShaderiv(vert, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vert, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
			<< infoLog << std::endl;
	}

	glGetShaderiv(frag, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(frag, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
			<< infoLog << std::endl;
	}

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::PROGRAM::SHADER::LINKING_FAILED\n"
			<< infoLog << std::endl;
	}

	glDeleteShader(vert);
	glDeleteShader(frag);
}
