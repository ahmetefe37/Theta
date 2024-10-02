workspace "Theta"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Theta/vendor/GLFW/include"
IncludeDir["Glad"] = "Theta/vendor/GLAD/include"

include "Theta/vendor/GLFW"
include "Theta/vendor/Glad"

project "Theta"
	location "Theta"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "thpch.h"
	pchsource "Theta/src/thpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"opengl32.lib",
		"Theta/vendor/GLFW/glfw3dll.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TH_PLATFORM_WINDOWS",
			"TH_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TH_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
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
		"Theta/vendor/spdlog/include",
		"Theta/src"
	}

	links
	{
		"Theta"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TH_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TH_DIST"
		optimize "On"