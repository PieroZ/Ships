workspace "Ships"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ships"
	location "Ships"
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
		"vendor/spdlog/include",
		"C:/dev/libs/cpp/SDL/SDL2/SDL2-2.28.5/include",
		"C:/dev/libs/cpp/SDL/SDL2-image/SDL2_image-2.8.2/include",
		"C:/dev/libs/cpp/SDL/SDL2-ttf/SDL2_ttf-2.20.2/include"
	}
	
	libdirs
	{
		"C:/dev/libs/cpp/SDL/SDL2/SDL2-2.28.5/lib/x64",
		"C:/dev/libs/cpp/SDL/SDL2-image/SDL2_image-2.8.2/lib/x64",
		"C:/dev/libs/cpp/SDL/SDL2-ttf/SDL2_ttf-2.20.2/lib/x64"
	}
	
	links 
	{
		"SDL2",
		"SDL2main",
		"SDL2_image"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL"
		}

		--postbuildcommands
		--{
		--	("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		--}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"