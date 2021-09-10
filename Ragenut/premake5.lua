project "Ragenut"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Rage/vendor/spdlog/include",
		"%{wks.location}/Rage/src",
		"%{wks.location}/Rage/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
	}

	links
	{
		"Rage"
	}

	filter "system:windows"
		systemversion "latest"

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
