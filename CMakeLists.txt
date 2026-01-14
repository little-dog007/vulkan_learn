cmake_minimum_required(VERSION 3.16)
project(BasicWindowsWindow)

set(PROJECT_NAME BasicWindowsWindow)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(${PROJECT_NAME}
    src/main.cpp
        src/vulkan_application.cpp
        src/vulkan_application.h
        src/util/util.cpp
)

if (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0601)
endif ()

if (WIN32)
    add_definitions(-D_AFXDLL)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
    # Link Windows libraries - comprehensive list for GUI applications
    target_link_libraries(${PROJECT_NAME} 
        user32.lib 
        gdi32.lib 
        kernel32.lib 
        comctl32.lib
    )
endif ()

find_package(Vulkan REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE  ${Vulkan_INCLUDE_DIRS})


if (WIN32)
    add_definitions(-D_AFXDLL)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
    # Link Windows libraries
    target_link_libraries(${PROJECT_NAME} user32 gdi32 kernel32 Vulkan::Vulkan)

ENDIF ()