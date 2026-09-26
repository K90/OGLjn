#version 330 core

in vec3 vertexColor;
uniform vec4 vertexChangeColor;

out vec4 FinalColor;

vec4 FragColor;

void main() {
	FragColor = vec4(vertexColor, 1.0);
	FinalColor = FragColor + vertexChangeColor;
}