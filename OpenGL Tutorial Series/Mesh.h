#ifndef MESH_H
#define MESH_H

#include "glm/glm.hpp"
#include "gl/glew.h"

struct Vertex
{
	Vertex(const glm::fvec3& pos)
	{
		this->pos = pos;
	}
private:
	glm::fvec3 pos;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	virtual ~Mesh();

	void Draw();

private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);

	enum
	{
		POSITION_VB,

		NUM_BUFFERS
	};

	GLuint mVertexArrayObject;
	GLuint mVertexArrayBuffers[NUM_BUFFERS];

	unsigned int mDrawCount;
};
#endif // MESH_H
