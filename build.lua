IncludeDir = {}
IncludeDir["GLFW"] =    "%{wks.location}/AtlasLib/vendor/glfw/include"
IncludeDir["spdlog"] =  "%{wks.location}/AtlasLib/vendor/spdlog/include"
IncludeDir["Glad"] =    "%{wks.location}/AtlasLib/vendor/Glad/include"

project "AtlasSandbox"
        kind "ConsoleApp"
        language "C++"
        
	targetdir ("%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
	objdir ("%{wks.location}/bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}")
        
        files
        {
                "source/**.h",
                "source/**.hpp",
                "source/**.cpp",
        }

        includedirs
        {
                "%{wks.location}/AtlasLib/source",
                "%{IncludeDir.spdlog}",
                "%{IncludeDir.Glad}",
        }

        links
        {
                "AtlasLib",
                "Glad",
        }

        filter "system:windows"
                cppdialect "C++latest"
                staticruntime "off"
                systemversion "latest"

                defines 
                {
                    "AT_PLATFORM_WINDOWS",
                }

        filter "configurations:Debug"
                defines "AT_DEBUG"
                symbols "on"
                runtime "Debug"

        filter "configurations:Release"
                defines "AT_RELEASE"
                optimize "on"
                runtime "Release"