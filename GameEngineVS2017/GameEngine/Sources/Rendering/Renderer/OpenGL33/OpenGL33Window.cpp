// Class Include
#include "Rendering/Renderer/OpenGL33/OpenGL33Window.hpp"

// Includes
#include <iostream> // std::cerr

namespace GameEngine {
	// GLFW error callback
	void errorCallback(int error, const char* errorDescription) {
		std::cerr << "Error code : " << error << ", description : " << errorDescription << "\n";
	}

	OpenGL33Window::~OpenGL33Window() {
		this->release(); // RAII
	}

	OpenGL33Window::OpenGL33Window(void) {}

	OpenGL33Window::OpenGL33Window(const WindowCreateInfo & wci) {
		this->initialize(wci);
	}

	void OpenGL33Window::initialize(const WindowCreateInfo & wci) {
		std::cout << "Initializing the OpenGL 3.3 window..." << "\n";

		/* GLFW CONFIGURATION */
		// GLFW init
		if (!glfwInit())
			throw std::runtime_error{ "Failed to initialize GLFW." };

		// Configure GLFW callback
		glfwSetErrorCallback(errorCallback);

		// Configure GLFW
		glfwWindowHint(GLFW_SAMPLES, 4);								// Activate anti alliesing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);					// Maximum version of GLFW required
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);					// Minimum version of GLFW required
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);			// Forward compatibility
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// GLFW last functional core (= we don't want previous core version)

		// Create the window - param : width, height, window's name, physical name of the monitor if full screen, window with which we would like to share resources
		this->_window = glfwCreateWindow(wci.getWidth(), wci.getHeight(), wci.getTitle(), nullptr, nullptr);

		if (!this->_window) {
			glfwTerminate();
			throw std::runtime_error{ "Failed to initialize the window." };
		}

		// Set this window as current context window
		glfwMakeContextCurrent(this->_window);

		/* GLEW CONFIGURATION */
		// We want to use the last functions of GLEW
		glewExperimental = GL_TRUE;

		// GLEW init
		if (glewInit() != GLEW_OK) {
			glfwTerminate();
			throw std::runtime_error{ "Failed to initialize GLEW." };
		}

		/* GAME LOOP */
		// Not to miss an input : when a key is released, will sent us true in any case
		glfwSetInputMode(this->_window, GLFW_STICKY_KEYS, GL_TRUE);

		std::cout << "OpenGL 3.3 window initialization is complete." << "\n";
	}

	void OpenGL33Window::release() {
		glfwTerminate();
		this->_window = nullptr;
		std::cout << "OpenGL 3.3 window released." << "\n";
	}
} // end namespace GameEngine