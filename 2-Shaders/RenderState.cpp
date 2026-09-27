#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

int renderState{};
bool nextKeyWasDown{false};
bool prevKeyWasDown{false};

int getcurrRenderState() {
	return renderState;
}

int scrollRenderState(GLFWwindow* window) {

	bool keyNextIsDown {glfwGetKey(window, GLFW_KEY_RIGHT_BRACKET) == GLFW_PRESS};
	if(keyNextIsDown && !nextKeyWasDown)
		renderState += 1;
	nextKeyWasDown = keyNextIsDown;

	bool keyPrevIsDown {glfwGetKey(window, GLFW_KEY_LEFT_BRACKET) == GLFW_PRESS};
	if(keyPrevIsDown && !prevKeyWasDown && renderState >= 1)
		renderState -= 1;
	prevKeyWasDown = keyPrevIsDown;

	return renderState;
}


