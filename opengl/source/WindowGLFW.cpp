
#include "WindowGLFW.hpp"

#include <iostream>

WindowGLFW::WindowGLFW(const char* name, int height, int width)
{
	/* Initialize the library */
	if (glfwInit() == GLFW_FALSE)
		throw new std::runtime_error("GLFW Initialization Failed in WindowGLFW::WindowGLFW");

	this->height = height;
	this->width = width;
	this->name = name;

	this->window = glfwCreateWindow(width, height, name, NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		throw new std::runtime_error("GLFW Window did not instantiate correctly");
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
}

WindowGLFW::~WindowGLFW()
{
	glfwTerminate();
}

bool WindowGLFW::shouldCloseWindow()
{
	/* Poll for and process events to then check if the window should be closed */
	glfwPollEvents();
	return glfwWindowShouldClose(this->window);
}

void WindowGLFW::swapBuffers()
{
	glfwSwapBuffers(this->window);
}
