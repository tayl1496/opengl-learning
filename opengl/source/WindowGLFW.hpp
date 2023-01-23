#pragma once
#include <GLFW/glfw3.h>

class WindowGLFW
{
	GLFWwindow* window;
	int height;
	int	width;
	const char* name;

public:
	WindowGLFW(const char* name, int height, int width);
	WindowGLFW() = delete;
	~WindowGLFW();
	bool shouldCloseWindow();
	void swapBuffers();

};
