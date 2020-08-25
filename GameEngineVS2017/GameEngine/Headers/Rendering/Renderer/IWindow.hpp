#ifndef IWINDOW_HPP
#define IWINDOW_HPP

// My includes
#include "WindowCreateInfo.hpp"

// Third Party libs
#include "Glew/glew.h"
#include "Glfw/glfw3.h"

// STL libs
#include <iostream>	// std::cerr

namespace GameEngine {
	/* Abstract Class */
	class IWindow {
	protected:
		GLFWwindow * _window = nullptr;

	public:
		virtual ~IWindow() = default;

		virtual void initialize(const WindowCreateInfo & wci) = 0;
		virtual void release() = 0;

		GLFWwindow * getWindow() const noexcept { return this->_window; }
	};
} // namespace GameEngine

#endif // IWINDOW_HPP