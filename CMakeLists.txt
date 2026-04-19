# 最低 CMake 版本要求
cmake_minimum_required(VERSION 3.15)

# 项目名称
project(WordCounter LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 引入头文件搜索路径（让所有代码能找到 include 里的 .h 文件）
include_directories(${PROJECT_SOURCE_DIR}/include)

# 自动收集 src 文件夹下所有cpp源文件
file(GLOB CPP_SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# 生成可执行程序
add_executable(${PROJECT_NAME} ${CPP_SOURCES})

# 可选：Windows下编译静态版本，运行无需额外dll
if(WIN32)
    set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded")
endif()
