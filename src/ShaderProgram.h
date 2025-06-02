#pragma once

#include <string>
#include <map>
#ifdef __APPLE__
#include <glad/glad.h>
#else
#include "GL/glew.h"
#endif
#include "glm/glm.hpp"
using std::string;


class ShaderProgram
{
public:
	 ShaderProgram();
	~ShaderProgram();

	enum class ShaderType
	{
		VERTEX,
		FRAGMENT,
		PROGRAM
	};

	bool LoadShaders(const char* vsFilename, const char* fsFilename);
	void Use();

	GLuint GetProgram() const;

	void SetUniform(const GLchar* name, const float& f);
	void SetUniform(const GLchar* name, const glm::vec2& v);
	void SetUniform(const GLchar* name, const glm::vec3& v);
	void SetUniform(const GLchar* name, const glm::vec4& v);
	void SetUniform(const GLchar* name, const glm::mat4& m);

	// We are going to speed up looking for uniforms by keeping their locations in a map
	GLint GetUniformLocation(const GLchar * name);

private:

	string FileToString(const string& filename);
	void  CheckCompileErrors(GLuint shader, ShaderType type);


	GLuint mHandle;
	std::map<string, GLint> mUniformLocations;
};
