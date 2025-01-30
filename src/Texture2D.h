#pragma once
#ifdef __APPLE__
#include <glad/glad.h>
#else
#include "GL/glew.h"
#endif
#include <string>
using std::string;

class Texture2D
{
public:
	Texture2D();
	virtual ~Texture2D();

	bool LoadTexture(const string& fileName, bool generateMipMaps = true);
	void Bind(GLuint texUnit = 0);

private:
	Texture2D(const Texture2D& rhs) = default;
	Texture2D& operator = (const Texture2D& rhs) = default;

	GLuint mTexture;
};
