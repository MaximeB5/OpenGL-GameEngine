#ifndef WINDOWCREATEINFO_HPP
#define WINDOWCREATEINFO_HPP

namespace GameEngine {
	class WindowCreateInfo {
	protected:
		unsigned int _windowWidth;
		unsigned int _windowHeight;
		const char* _windowTitle;

	public:
		// Constructor
		WindowCreateInfo(unsigned int width, unsigned int height, const char* title) : _windowWidth(width), _windowHeight(height), _windowTitle(title) {}

		// Getters
		unsigned int getWidth (void) const noexcept	{ return this->_windowWidth;  }
		unsigned int getHeight(void) const noexcept { return this->_windowHeight; }
		const char*  getTitle (void) const noexcept	{ return this->_windowTitle;  }
	};
} // end namespace GameEngine

#endif // WINDOWCREATEINFO_HPP