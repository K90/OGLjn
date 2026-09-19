#include <glad/glad.h>
#include <glfw3.h> 
#include <iostream>
#include "window.h"


void processInput(GLFWwindow* window);

int main() {

	GLFWwindow* window = createWindow();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialise GLAD" << std::endl;
		return -1;
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

