#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

#include "ShaderProgram.h"
#include "Window.h"

const int INITIAL_WINDOW_WIDTH {600};
const int INITIAL_WINDOW_HEIGHT {600};

GLFWwindow* createWindow() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window {glfwCreateWindow(INITIAL_WINDOW_WIDTH, INITIAL_WINDOW_HEIGHT, "3-Textures",NULL, NULL)};
	if (!window) {
		std::cout << "Failed to create GLFW window." << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialise GLAD." << std::endl;
	}

	if (window) {
		std::cout 
			<< "OGLVendor: " << glGetString(GL_VENDOR) << "\n"
			<< "Renderer: " << glGetString(GL_RENDERER) << "\n"
			<< "OGLVersion: " << glGetString(GL_VERSION) << "\n"
			<< "GLSLVersion: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n\n\n";
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	return window;
}

void handleInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
