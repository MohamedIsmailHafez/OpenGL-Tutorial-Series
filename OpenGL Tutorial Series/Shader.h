#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "GL/glew.h"

class Shader
{
public:
	explicit Shader(const std::string& fileName);

	void Bind();

	virtual ~Shader();

private:

	enum class SHADER_TYPE : unsigned {
		VERTEX_SHADER = 0,
		FRAGMENT_SHADER = 1
	};

	Shader();
	Shader(const Shader& other);
	void operator=(const Shader& other);

	std::string LoadShader(const std::string& fileName);

	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

	GLuint CreateShader(const std::string& source, unsigned int shaderType);


	static const unsigned int NUM_SHADERS = 2;	//Currently supporting Vertex & Fragment Shaders.

	GLuint mProgram;
	GLuint mShaders[NUM_SHADERS];
};
#endif // SHADER_H
