#pragma once

#include "../Events/EngineEvents.h"

namespace Wandering {

	class WANDERING_API Window {
	public:
		virtual void initWindow() = 0;
		virtual bool getKeyDown(keyboardButtons key) = 0;
		virtual bool getMouseDown(MouseButtons button) = 0;

	private:
		virtual void mouseDownCallBack() = 0;
		virtual void mouseUpCallBack() = 0;
		virtual void keyDownCallBack() = 0;
		virtual void keyUpCallBack() = 0;

	};
}