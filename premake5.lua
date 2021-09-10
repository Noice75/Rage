include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Rage"
	architecture "x86_64"
	startproject "Ragenut"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Rage/vendor/GLFW"
	include "Rage/vendor/Glad"
	include "Rage/vendor/imgui"
	include "Rage/vendor/yaml-cpp"
group ""

include "Rage"
include "Sandbox"
include "Ragenut"
