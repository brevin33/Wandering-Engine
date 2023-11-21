#pragma once
#include "Window.h"

namespace Wandering {

	class wdGLFWWindow {
	public:
		void initWindow() ;
		bool getKeyDown(keyboardButtons key);
		bool getMouseDown(MouseButtons button);

	private:
		void mouseDownCallBack();
		void mouseUpCallBack();
		void keyDownCallBack();
		void keyUpCallBack();

	};
}