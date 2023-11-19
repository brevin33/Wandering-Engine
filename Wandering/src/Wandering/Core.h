#pragma once

#ifdef WD_PLATFORM_WINDOWS
	#ifdef WD_BUILD_DLL
		#define WANDERING_API __declspec(dllexport)
	#else
		#define WANDERING_API __declspec(dllimport)
	#endif
#else
	#error Wandering olny works on Windows
#endif