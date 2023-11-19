#pragma once

#ifdef WAND_PLATFORM_WINDOWS
	#ifdef WAND_BUILD_DLL
		#define WANDERING_API __declspec(dllexport)
	#else
		#define WANDERING_API __declspec(dllimport)
	#endif
#else
	#error Wandering olny works on Windows
#endif