#pragma once

GLFWwindow* createWindow();

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void getOpenGLInfo();