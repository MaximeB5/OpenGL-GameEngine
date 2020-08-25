// Third Party libs
//#include "Glew/glew.h"
//#include "Glfw/glfw3.h"

// STL libs
#include <iostream>	// std::cerr

/*
// GLFW error callback
void errorCallback(int error, const char* errorDescription) {
	std::cerr << "Error code : " << error << ", description : " << errorDescription << "\n";
}
*/

#include "Rendering/Renderer/OpenGL33/OpenGL33Window.hpp"

int main(int argc, char** argv) {
	std::cout << "CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC \n";
	GameEngine::WindowCreateInfo wci{ 1280, 720, "Game Engine 2" };
	// GameEngine::OpenGL33Window window{ wci };
	GameEngine::OpenGL33Window window;

	try
	{
		window.initialize(wci);
	}
	catch (const std::runtime_error& re)
	{
		std::cerr << "window.initialize(wci) exception : " << re.what() << "\n";
		return -1;
	}
	
	GLFWwindow * pWindow = window.getWindow();

	// Run the game as long as the window is opened and the user didn't press the Escape key
	while (!glfwWindowShouldClose(pWindow) && glfwGetKey(pWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		//One buffer writes the frame, the other buffer writes the buffer on the screen. And then they swap their role, and so on.
		glfwSwapBuffers(pWindow);

		// Make the window responsive to the events (such as the Escape key)
		glfwPollEvents();
	}

	/* GLFW CONFIGURATION */
	/*
	// GLFW init
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << "\n";
		return -1;
	}

	// Configure GLFW callback
	glfwSetErrorCallback(errorCallback);

	// Configure GLFW
	glfwWindowHint(GLFW_SAMPLES, 4);								// Activate anti alliesing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);					// Maximum version of GLFW required
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);					// Minimum version of GLFW required
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);			// Forward compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// GLFW last functional core (= we don't want previous core version)

	// Create the window - param : width, height, window's name, physical name of the monitor if full screen, window with which we would like to share resources
	GLFWwindow * window{ glfwCreateWindow(1280, 720, "Game Engine", nullptr, nullptr) };

	if (!window) {
		glfwTerminate();
		std::cerr << "Failed to initialize the window" << "\n";
		return -1;
	}

	// Set this window as current context window
	glfwMakeContextCurrent(window);
	*/

	/* GLEW CONFIGURATION */
	/*
	// We want to use the last functions of GLEW
	glewExperimental = GL_TRUE;
	
	// GLEW init
	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		std::cerr << "Failed to initialize GLEW" << "\n";
		return -1;
	}
	*/

	/* GAME LOOP */
	/*
	// Not to miss an input : when a key is released, will sent us true in any case
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Run the game as long as the window is opened and the user didn't press the Escape key
	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		//One buffer writes the frame, the other buffer writes the buffer on the screen. And then they swap their role, and so on.
		glfwSwapBuffers(window);

		// Make the window responsive to the events (such as the Escape key)
		glfwPollEvents();
	}
	
	glfwTerminate();
	*/
	return 0;
}