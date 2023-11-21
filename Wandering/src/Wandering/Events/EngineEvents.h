#pragma once
#include "../Core.h"
namespace Wandering {

	// mouse events

	enum WANDERING_API MouseButtons {
		LeftButton = 0,
		RightButton = 1,
	};

	struct WANDERING_API mouseDownEvent {
		float mouseX, mouseY;
		MouseButtons mouseButton;
	};

	struct WANDERING_API mouseUpEvent {
		float mouseX, mouseY;
		MouseButtons mouseButton;
	};

	struct WANDERING_API mouseMoveEvent {
		float mouseX, mouseY;
	};

	// keyboard events

	enum WANDERING_API keyboardButtons {
		aKey,
		bKey,
		cKey,
		dKey,
		eKey,
		fKey,
		gKey,
		hKey,
		iKey,
		jKey,
		kKey,
		lKey,
		mKey,
		nKey,
		oKey,
		pKey,
		qKey,
		rKey,
		sKey,
		tKey,
		uKey,
		vKey,
		wKey,
		xKey,
		yKey,
		zKey,
		shiftKey,
		enterKey,
	};

	struct WANDERING_API keyDownEvent {
		keyboardButtons buttonPressed;
	};

	struct WANDERING_API keyUpEvent {
		keyboardButtons buttonPressed;
	};

}