-- all paths whether location, targetdir, objdir, files, includedirs are all 
-- resolved relative to the .lua file location.

-- Paths in .lua		Where premake5.lua lives	C:\dev\HZL\
-- Paths in .vcxproj	Where .vcxproj lives		C:\dev\HZL\HZL\

workspace "HZL"
	architecture "x64"
	--startproject "Sandbox"

	configurations {
		"Debug",
		"Release", 
		"Dist"
	}
	startproject "Sandbox"

--	Debug-Windows-x64	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


--Generate HZL.vcxproj and place it inside the HZL/ folder
project "HZL"			-- Generate HZL.vcxproj
	location "HZL"		-- and place it inside the HZL/ folder
	kind "SharedLib"	
	language "C++"

	-- targetdir and objdir is relative to where .lua lives.
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs {
		"%{prj.name}/src/",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"		
		systemversion "latest"
		buildoptions {"/utf-8"}
		
	defines {
		"HZL_PLATFORM_WINDOWS",
		"HZL_BUILD_DLL"
	}

	--postbuildcommands are relative to where .vcxproj lives. #
	--always a problem: postbuildcommands executes immediately after the project it belongs  &
	--to finishes building — it does not wait for other projects. #
	postbuildcommands {
		--if it is relpath, it is relative to the .vcxproj
		("{COPY} %{cfg.buildtarget.relpath}  ../bin/"..outputdir.."/Sandbox/" )	
		--if it is abspath, also works as the real path got resolved at building time. 
		--("{COPY} %{cfg.buildtarget.abspath}  ../bin/"..outputdir.."/Sandbox/" )	
	}


	filter "configurations:Debug"
		defines "HZL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZL_DIST"
		optimize  "On"


project "Sandbox" 
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs {
		"HZL/vendor/spdlog/include",
		"HZL/src"
	}

	links {
		"HZL"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"		
		systemversion "latest"
		buildoptions {"/utf-8"}
		
	defines {
		"HZL_PLATFORM_WINDOWS"
	}

	-- put the copy .dll commands here so it could execute after the bin/targetdir/Sandbox is created.
	--postbuildcommands {
		--hard coded destination:
		--("{COPY}  ../bin/"..outputdir.."/HZL/HZL.dll   ../bin/"..outputdir.."/Sandbox/" )	
		--use token to represent destination:
		--("{COPY}  ../bin/"..outputdir.."/HZL/HZL.dll   %{cfg.buildtargetdir}" )	
	--}
	--The downside of moving the copy .dll task to Sandbox project is that, if the HZL project get rebuild, the .dll
	--is not copied automatically to Sandbox project. It is only when the Sandbox rebuild that it copy .dll to Sandbox.
	--which means, everytime we change something in HZL and get a new .dll, we have to rebuild Sandbox also to copy the 
	--.dll to Sandbox. This is not worth. Would rather move the copy task to the HZL project. 



	filter "configurations:Debug"
		defines "HZL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HZL_DIST"
		optimize  "On"


