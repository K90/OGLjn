#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

#include "Window.h"

int main() {
	
	GLFWwindow* window = createWindow();

	float vertices [] = {
	
		 0.0f,  0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f,
		 0.5f, -0.5f,  0.0f
	
	};

	while (!glfwWindowShouldClose(window)) {
	
		processQuit(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
