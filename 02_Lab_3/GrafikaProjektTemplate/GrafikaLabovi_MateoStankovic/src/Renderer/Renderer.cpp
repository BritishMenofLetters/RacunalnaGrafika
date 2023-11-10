#include "Renderer.h"

void Renderer::Clear()
{
	glClearColor(0.5f, 0.4f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
