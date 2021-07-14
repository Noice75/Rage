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

group "Dependencies"
	include "Rage/vendor/GLFW"
	include "Rage/vendor/Glad"
	include "Rage/vendor/imgui"

group ""

project "Rage"
	location "Rage"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
    staticruntime "on"

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

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
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
		systemversion "latest"

		defines
		{
			"RA_PLATFORM_WINDOWS",
			"RA_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "RA_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "RA_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Rage/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Rage"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"RA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RA_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "RA_DIST"
		runtime "Release"
		optimize "on"