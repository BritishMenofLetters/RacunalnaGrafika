#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
layout (location = 2) in vec2 aTexCord;
layout (location = 3) in vec3 aColor; // the color variable has attribute position 3


in vec4 fColor;

out vec3 normal;
out vec2 TexCord;
out vec3 FragColor;


uniform float xOffset;
uniform float yOffset;

void main()
{ 
	gl_Position=vec4(aPos.x + xOffset, aPos.y + yOffset, aPos.z, 1.0f);

	normal=aNorm;
	TexCord=aTexCord;
	FragColor = aColor;

}