#include <iostream>
#include <GL/glew.h>
#include "Renderer.h"
#include "Shader.h"
#include "Mesh.h"


int main(int argc, char** argv)
{
	Renderer renderer(800, 600, "OpenGL Window");

	Shader shader("./resources/shaders/basicShader");

	Vertex vertices[] = { Vertex(glm::fvec3(-0.5, -0.5, 0)),
						  Vertex(glm::fvec3( 0.5, -0.5, 0)),
						  Vertex(glm::fvec3( 0.0,  0.5, 0))};

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
		
	while(!renderer.IsClosed())
	{
		renderer.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		shader.Bind();

		mesh.Draw();

		renderer.Update();
	}

	return 0;
}