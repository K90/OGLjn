#version 460

in vec4 triangleColor;

vec4 FragColor;

void main() {
	
	FragColor = vec4(triangleColor, 1.0f);

}