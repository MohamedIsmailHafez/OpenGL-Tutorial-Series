#include <iostream>
#include <GL/glew.h>
#include "Renderer.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"

int main(int argc, char** argv)
{
	Renderer renderer(800, 600, "OpenGL Window");

	Shader shader("./resources/shaders/basicShader");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0, 0) ),
						  Vertex(glm::vec3( 0.5, -0.5, 0), glm::vec2(1, 0) ),
						  Vertex(glm::vec3( 0.0,  0.5, 0), glm::vec2(0.5, 1) )};

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
	
	Texture texture("./resources/textures/bricks.jpg");

	Transform transform;

	while(!renderer.IsClosed())
	{
		renderer.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		shader.Bind();

		texture.Bind(0);

		shader.Update();

		mesh.Draw();

		renderer.Update();
	}

	return 0;
}