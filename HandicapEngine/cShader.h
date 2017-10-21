#pragma once
#include<GL\glew.h>
#include"Helpers.h"
class cShader
{
private:
	GLuint shader_ID;
	const char *vertex_Path;
	const char *frag_Path;
public:
	cShader(const char* vPath, const char* fPath ) ;
	~cShader();
	void enable() const;
	void disable() const;
	inline GLuint get_Shader_ID() const { return shader_ID; }
private:
	GLuint create();
	void check_Errors(const GLuint &shader, const std::string &shader_title);

};

