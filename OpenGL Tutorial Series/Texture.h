#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include "gl/glew.h"

class Texture
{
public:
	Texture(const std::string& fileName);

	void Bind(unsigned int fUnit);

	virtual ~Texture();

private:
	GLuint mTexture; //OpenGL Texture Handle.
};
#endif	//!TEXTURE_H
