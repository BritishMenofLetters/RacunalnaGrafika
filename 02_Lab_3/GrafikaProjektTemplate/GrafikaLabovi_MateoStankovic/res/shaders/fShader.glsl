#version 330 core

in vec3 normals;
in vec2 TexCord;

out vec4 fColor;

uniform sampler2D tex;

void main()
{
	// fColor=texture(tex, TexCord);
	// fColor.rgb = vec3(0.3f, 0.2f, 0.5f);
	// fColor.a   = 1;

	// fColor.x = TexCord.x;
	// fColor.y = TexCord.y;

	// fColor=mix(texture(tex, TexCord), texture(tex, vec2(1.0-TexCord.x, TexCord.y)), 0.5);

	fColor=texture(tex, vec2(TexCord.x * 2, TexCord.y * 2));


}