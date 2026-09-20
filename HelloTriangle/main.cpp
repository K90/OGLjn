#include <glad/glad.h>
#include <glfw3.h> 
#include <iostream>
#include "window.h"

const char *vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main() {\n"
	" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

const char *fragmentShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main() {\n"
	" FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\0";

void processInput(GLFWwindow* window);

int main() {

	GLFWwindow* window = createWindow();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialise GLAD" << std::endl;
		return -1;
	}

	//vertex input

	float vertices [] = {															//define normalized device coords
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f

	};

	unsigned int VBO;																//vbos can store large amounts of vertex data on the gpu
	glGenBuffers(1, &VBO);															//generate one with a buffer ID using glGenBuffers func

	glBindBuffer(GL_ARRAY_BUFFER, VBO);												/*Any buffer calls made on GL_ARRAY_BUFFER is now used
																					  to configure the correctly bound buffer, which is VBO*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);		//copy vertex data to buffers memory

	//vertex shader
	unsigned int vertexShader;														//define object so we can dynamically compile vertshader 
	vertexShader = glCreateShader(GL_VERTEX_SHADER);								//at runtime, so we pass GL_VERTEX_SHADER

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);						//attatch shader source to shader object
	glCompileShader(vertexShader);													

	//fragment shader
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
	}

	//render loop
	while (!glfwWindowShouldClose(window)) {

		//input
		processInput(window);

		//rendering commands
		glClear(GL_COLOR_BUFFER_BIT);

		//check and call events and swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

