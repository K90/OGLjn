#ifndef WINDOW_H
#define WINDOW_H

GLFWwindow* createWindow();

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void getOpenGLInfo();

#endif // !WINDOW_H