#include<iostream>
#include"cWindow.h"
#include"Helpers.h"
#include "Maths.h"
#include"cShader.h"
int main()
{
	using namespace std;


	cWindow win(640, 480, "Game");
	
	glClearColor(0.1f, 1.0f, 0.25f, 1.0f);
	GLfloat vertex[] = {
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f,  0.5f, 0.0f,
		0.5f,  0.5f, 0.0f,
		0.5f,  -0.5, 0.0f,
		-0.5f, -0.5f, 0.0f

	};


	GLuint vob;
	glGenBuffers(0, &vob);
	glBindBuffer(GL_ARRAY_BUFFER, vob);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	
	cShader shader("basic.vert", "basic.frag");
	shader.enable();



	 
	while(!win.window_closed()) {
		
		if (win.is_key_pressed(GLFW_KEY_ESCAPE))
			return 0;
		
		if (win.is_key_pressed(GLFW_KEY_A))
			cout << "A key pressed " << endl;
		//cout << win.is_key_pressed(GLFW_KEY_A) << endl;
		double x, y;
		win.get_mouse_cursor_pos(x, y);
		//cout << x << "," << y << endl;


		if (win.is_mouse_button_pressed(GLFW_MOUSE_BUTTON_1))
		{
			cout << "Mouse button 1 pressed " << x<<":"<< y<< endl;

		}


		if (win.is_mouse_button_pressed(GLFW_MOUSE_BUTTON_2))
		{
			cout << "Mouse button 2 pressed" << endl;

		}
	

		win.clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		
		win.update();
		

	}

	return 0; 
}