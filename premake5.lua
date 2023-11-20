workspace "Wandering"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Wandering"
	location "Wandering"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "wdpch.h"
	pchsource "Wandering/src/Wandering/wdpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WD_PLATFORM_WINDOWS",
			"WD_BUILD_DLL"
		}

		   postbuildcommands   
		   {
			   ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/WanderingApp")
		   }


	filter "configurations:Debug"
		defines "WD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WD_DIST"
		optimize "On"

project "WanderingApp"
	location "WanderingApp"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Wandering/vendor/spdlog/include",
		"Wandering/src"
	}

	links
	{
		"Wandering"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"WD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "WD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "WD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "WD_DIST"
		optimize "On"