#pragma once
#include <wdpch.h>
namespace Wandering {
	extern struct vertex;

	class Mesh {
		void virtual loadFromVertices(std::vector<vertex>) = 0;

		void virtual loadFromObj(std::string filePath) = 0;
	};

}