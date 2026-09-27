#pragma once

int getcurrRenderState();
int scrollRenderState(GLFWwindow* window);

void applyDynamicColoring(int shaderProgram);
void resetColorToDefault(int shaderProgram);