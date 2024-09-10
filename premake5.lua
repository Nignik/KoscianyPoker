workspace "KoscianyPoker"
    configurations {"Debug", "Release"}
    architecture "x86_64"

    filter { "configurations:Debug" }
    symbols "On"

    filter { "configurations:Release" }
    optimize "On"

    targetdir ("Build/Bin/%{prj.name}/%{cfg.longname}")
    objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")

project "KoscianyPoker"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    files {
        "src/**.h", "src/**.cpp"
    }