#pragma once
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32
class cWindow
{
public:
	cWindow(int aWidth, int aHeigt, char *aName);
	~cWindow();

private:
	static bool keys[MAX_KEYS];
	static bool mouse_Buttons[MAX_BUTTONS];
	static double mouse_X, mouse_Y;
	int heigth;
	int width;
	char* title;
	GLFWwindow* window;
public:
	int get_Heigth() const;
	int get_Width() const;
	char *get_name() const;
	void clear() const;
	void update() ;
	static bool is_key_pressed(unsigned int key_code);
	static bool is_mouse_button_pressed(unsigned int button_code);
	static void get_mouse_cursor_pos(double& x, double& y);
	bool window_closed() const;
private:
	bool init();
	friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	
	
};

