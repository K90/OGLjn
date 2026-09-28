#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

#include "Window.h"

const GLuint SCR_WIDTH = 600;
const GLuint SCR_HEIGHT = 600;

GLFWwindow* createWindow() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "3-Textures!", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (window) {
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << "\n"
				<< "Renderer: " << glGetString(GL_RENDERER) << "\n"
				<< "OGLVersion: " << glGetString(GL_VERSION) << "\n"
				<< "GLSLVersion: " << glGetString(GL_SHADING_LANGUAGE_VERSION)
				<< std::endl;
	}

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialise GLAD" << std::endl;
	}

	return window;
}
	
void processQuit(GLFWwindow* window) {
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}