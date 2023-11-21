#pragma once
#include <wdpch.h>
#include "Mesh.h"
namespace Wandering {

	class Renderer {
	public:
		virtual void drawMesh(std::string fragShader, std::string vertShader, Mesh mesh) = 0;
	};

}