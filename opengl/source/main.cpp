#include <iostream>
#include <GL/glew.h>
#include "WindowGLFW.hpp"


int main(void)
{
	WindowGLFW window = WindowGLFW("OpenGl Learning", 800, 600);

	glewInit();

	std::cout << "OpenGl Version : " << glGetString(GL_VERSION) << std::endl;

	/* Loop until the user closes the window */
	while (!window.shouldCloseWindow())
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		/* Swap front and back buffers */
		window.swapBuffers();
	}
	return EXIT_SUCCESS;
}