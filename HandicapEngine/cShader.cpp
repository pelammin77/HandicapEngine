#include "cShader.h"
#include<iostream>
#include<vector>

cShader::cShader(const char* vPath, const  char* fPath)
	:vertex_Path(vPath), frag_Path(fPath)
{
	//vertex_Path = vPath;
	//frag_Path = fPath;
	shader_ID = create();
    
}


cShader::~cShader()
{
	glDeleteProgram(shader_ID);
}

void cShader::enable() const
{
	glUseProgram(shader_ID);

}

void cShader::disable() const
{
	glUseProgram(0);
}

GLuint cShader::create()
{
	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		std::cout << "Error" << glewGetErrorString(GlewInitResult);
		exit(EXIT_FAILURE);

	}


	GLuint program = glCreateProgram();
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
	std::string v_source = read_file(vertex_Path);
	std::string f_source = read_file(frag_Path);
	const char *v = v_source.c_str();
	const char *f = f_source.c_str();

	glShaderSource(vertex, 1, &v, NULL);
	glShaderSource(fragment, 1, &f, NULL);

	glCompileShader(vertex);


	GLint result;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{   

		/*
	
		//check_Errors(vertex);
		GLint l;
		glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &l);
		std::vector<char>err(l);
		glGetShaderInfoLog(vertex, l, &l, &err[0]);
		std::cout << "Failed to coplite the vertex shader!!" << std::endl << err[0];
		glDeleteShader(vertex);
	*/
	
		check_Errors(fragment, "vertex");
		return 0;
	}
	else {
		std::cout << std::endl << "Vertex shader complite" << std::endl;
	}
	
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
	
	if (result == GL_FALSE)
	{
		check_Errors(fragment, "fragment");
		/*
		GLint l;
		glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &l);
		std::vector<char>err(l);
		glGetShaderInfoLog(fragment, l, &l, &err[0]);
		std::cout << "Failed to coplite the fragment shader!!" << std::endl << err[0];
		glDeleteShader(fragment);
		*/


		return 0;
	}

	else {
		std::cout << "Fragment shader complite" << std::endl;
	}

	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glValidateProgram(program);
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	
	return program;
}

void cShader::check_Errors(const GLuint &shader, const std::string &shader_title)
{
	GLint lenght;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &lenght);
	std::vector<char>err(lenght);
	glGetShaderInfoLog(shader, lenght, &lenght, &err[0]);
	std::cout << "Failed to coplite the "<<shader_title<<" shader!! " << &err[0]<< " errors";
	glDeleteShader(shader);
}
