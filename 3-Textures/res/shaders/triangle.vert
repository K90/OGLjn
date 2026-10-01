#version 460

layout (location = 0) in vec3 aPos;

out vec4 triangleColor;

void main() {
	
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);
	triangleColor = vec4(aPos.x, aPos.y, aPos.z, 1.0f);

}