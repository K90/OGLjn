#include <glad/glad.h>
#include <glfw3.h> 
#include <vector>
#include <iostream>
#include "window.h"
#include "input_handler.h"



void processInput(GLFWwindow* window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

}