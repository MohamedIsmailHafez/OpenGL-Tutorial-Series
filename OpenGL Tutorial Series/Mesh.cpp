#include "Mesh.h"


Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	mDrawCount = numVertices;

	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);

	glGenBuffers(NUM_BUFFERS, mVertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[POSITION_VB]);

	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &mVertexArrayObject);
}

void Mesh::Draw()
{
	glBindVertexArray(mVertexArrayObject);

	glDrawArrays(GL_TRIANGLES, 0, mDrawCount);

	glBindVertexArray(0);
}
