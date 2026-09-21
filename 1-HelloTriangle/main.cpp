//hello two triangles
#include <glad/glad.h>
#include <glfw3.h> 
#include <iostream>
#include "window.h"
#include "input_handler.h"

const char *vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n" //needs re-reading
	"void main() {\n"
	" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

const char *fragmentShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n" //needs re-reading
	"void main() {\n"
	" FragColor = vec4(0.2f, 0.5f, 0.5f, 1.0f);\n"
	"}\0";



int main() {

	GLFWwindow* window = createWindow();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialise GLAD" << std::endl;
		return -1;
	}


	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);													


	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);


	int vertSuccess;
	int fragSuccess;
	char vertInfoLog[512];
	char fragInfoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertSuccess);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragSuccess);
	if (!vertSuccess) {
		glGetShaderInfoLog(vertexShader, 512, NULL, vertInfoLog);
		std::cout << "--ERROR::SHADER::VERTEX::COMPILATION_FAILED--\n" << 
			vertInfoLog << std::endl;
	}
	if (!fragSuccess) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, fragInfoLog);
		std::cout << "--ERROR::SHADER::FRAGMENT::COMPILATION_FAILED--\n"<< 
			fragInfoLog << std::endl;
	} //pondered over this structure, cant find a better way
	  //to specify erros between the linking and compiling (line 80)


	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int linkSuccess;
	char linkInfoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkSuccess);
	if (!linkSuccess) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, fragInfoLog);
		std::cout <<"--ERROR::PROGRAM::SHADERS::LINKING_FAILED--\n" <<
			linkInfoLog << std::endl;
	}//furthermore, im lazy and need to move on ^^ will figure it out in
	 //2-Shaders 

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	float vertices [] = {
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};

	unsigned int indices [] = {
		0, 1, 3,
		1, 2, 3
	};

	unsigned int VBO, VAO, EBO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//needs re-reading

	glBindBuffer(GL_ARRAY_BUFFER, 0);//needs re-reading

	glBindVertexArray(0);//needs re-reading

	while (!glfwWindowShouldClose(window)) {

		processInput(window);


		glClear(GL_COLOR_BUFFER_BIT);
	
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}


