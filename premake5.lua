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
IncludeDir["Glad"] = "Theta/vendor/Glad/include"

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

	filter "system:linux"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		libdirs
		{
			"Theta/vendor/GLFW/src"
		}

		links 
		{ 
			"Glad",           -- If you're using Glad
			"glfw3",           -- GLFW for OpenGL
			"GL",             -- OpenGL
			"GLU",
			"dl",             -- Dynamic linking
			"pthread"         -- POSIX threads

		}

		defines
		{
			"TH_PLATFORM_LINUX",
			"GLFW_INCLUDE_NONE"
		}

		buildoptions { "-fPIC" }  -- Position Independent Code is necessary for shared libraries on Linux
        postbuildcommands 
		{
			 "{COPY} %{cfg.buildtarget.relpath} ../bin/%{cfg.buildcfg}" 
		}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		links 
		{ 
			"GLFW",
			"Glad",
			"opengl32.lib",
			"Theta/vendor/GLFW/glfw3dll.lib"
		}
		
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
		"Theta/src",
		"Theta/vendor/GLFW/include",
	}

	libdirs
	{
		"Theta/vendor/GLFW/src"
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

	
	filter "system:linux"
        cppdialect "C++17"
        staticruntime "On"

        defines
        {
            "TH_PLATFORM_LINUX"
        }

        links 
		{ 
			"Glad",           -- If you're using Glad
			"glfw",           -- GLFW for OpenGL
			"GL",             -- OpenGL
			"dl",             -- Dynamic linking
			"pthread"         -- POSIX threads
		}

        -- Ensure Position Independent Code (PIC) is used for shared libraries
        buildoptions { "-fPIC" }

		
	filter "configurations:Debug"
		defines "TH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TH_DIST"
		optimize "On"