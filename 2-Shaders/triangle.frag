#version 330 core

in vec3 vertexColor;
in vec3 relativeColor;
uniform vec4 vertexChangeColor;

out vec4 FinalColor;

vec4 FragColor;

void main() {
	FragColor = vec4(relativeColor, 1.0f);
	FinalColor = FragColor + vertexChangeColor;
}