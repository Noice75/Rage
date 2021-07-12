workspace "Rage"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Rage/vendor/GLFW/include"
IncludeDir["Glad"] = "Rage/vendor/Glad/include"
IncludeDir["ImGui"] = "Rage/vendor/imgui"
IncludeDir["glm"] = "Rage/vendor/glm"

include "Rage/vendor/GLFW"
include "Rage/vendor/Glad"
include "Rage/vendor/imgui"

project "Rage"
	location "Rage"
	kind "SharedLib"
	language "C++"
    staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rapch.h"
	pchsource "Rage/src/rapch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
	    "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"RA_PLATFORM_WINDOWS",
			"RA_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "RA_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RA_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "RA_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Rage/vendor/spdlog/include",
		"Rage/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Rage"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"RA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RA_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RA_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "RA_DIST"
		runtime "Release"
		optimize "On"