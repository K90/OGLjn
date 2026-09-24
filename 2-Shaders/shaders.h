#pragma once

GLuint initVertexShader();
GLuint initFragmentShader();
GLuint initShaderProgram(GLuint vert, GLuint frag);
void testAndClean(GLuint vert, GLuint frag, GLuint program);