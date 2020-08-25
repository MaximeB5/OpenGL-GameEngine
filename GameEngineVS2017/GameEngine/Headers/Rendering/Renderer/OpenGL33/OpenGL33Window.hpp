#ifndef OPENGL33WINDOW_HPP
#define OPENGL33WINDOW_HPP

#include "Rendering/Renderer/IWindow.hpp"

namespace GameEngine {
	class OpenGL33Window : public IWindow{
	protected:

	public:
		OpenGL33Window(void);
		OpenGL33Window(const WindowCreateInfo & wci);
		~OpenGL33Window() override;

		void initialize(const WindowCreateInfo & wci) final;
		void release() final;
	};
} // end namespace GameEngine

#endif // OPENGL33WINDOW_HPP