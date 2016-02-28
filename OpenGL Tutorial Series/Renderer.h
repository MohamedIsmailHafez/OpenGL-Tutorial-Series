#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <GL/glew.h>
#include <SDL2/SDL.h>

class Renderer
{
public:
	Renderer(int fWidth, int fHeight, const std::string& fTitle);
	virtual ~Renderer(void);

	void Clear(GLfloat fRed, GLfloat fGreen, GLfloat fBlue, GLfloat fAlpha);
	void Update();

	bool IsClosed() const;

private:
	void PrintGPUSpecs();

	SDL_Window*		mWindow;
	SDL_GLContext	mGLContext;
	bool			mIsClosed;
};


#endif // RENDERER_H

