#include "cWindow.h"


  bool cWindow::keys[MAX_KEYS];
  bool cWindow::mouse_Buttons[MAX_BUTTONS];
  double cWindow::mouse_X;
  double cWindow::mouse_Y;
	  
cWindow::cWindow(int aWidth, int aHeigt, char *aName)
{
	width = aWidth;
	heigth = aHeigt;
	title = aName;

	
 if(init()==false)
  {
	  glfwTerminate();
  }

 for (int i = 0; i < MAX_KEYS; i++)
 {
	 keys[i] = false;
	 
   }
 for (int i = 0; i < MAX_BUTTONS; i++)
 {
	 mouse_Buttons[i] = false;

   }

}


cWindow::~cWindow()
{
	glfwTerminate();
}

int cWindow::get_Heigth() const
{
	return heigth;
}

int cWindow::get_Width() const
{
	return width;
}

char * cWindow::get_name() const
{
	return title;
}

void cWindow::clear() const
{ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void cWindow::update() 
{
	glfwPollEvents();
	glfwGetFramebufferSize(window, &width, &heigth);
	glViewport(0, 0, width, heigth);
	glfwSwapBuffers(window);
}


bool cWindow::is_key_pressed(unsigned int key_code)
{
	if (key_code > MAX_KEYS) 
	{
		std::cout << "Invald key code";
		return false;
	}
	return  keys[key_code];
}

bool cWindow::is_mouse_button_pressed(unsigned int button_code)
{
	if (button_code > MAX_BUTTONS)
	{
		std::cout << "Invald mouse button";
		return false;
	}


	return mouse_Buttons[button_code];
}

void cWindow::get_mouse_cursor_pos(double & x, double & y)
{
	x = mouse_X  ;
	y = mouse_Y ;
}

bool cWindow::window_closed() const
{ 
	return glfwWindowShouldClose(window)==1;

}

bool cWindow::init()
{
	if (!glfwInit()) {
		std::cout << "Error to create window";
		return false;
	}
	window = glfwCreateWindow(width, heigth, title, NULL, NULL);	
	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Glew error" << std::endl;
		return false;
	}
	return true;
}

//End of class

// Funtions

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	cWindow *w = (cWindow*) glfwGetWindowUserPointer(window);
	 ; 
	w->keys[key] = action != GLFW_RELEASE; // if key is pressed 
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	cWindow *w = (cWindow*)glfwGetWindowUserPointer(window);
	w->mouse_Buttons[button] = action != GLFW_RELEASE; // if button is pressed
     
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	cWindow *w = (cWindow*)glfwGetWindowUserPointer(window);
	w->mouse_X = xpos;
	w->mouse_Y = ypos;
}
