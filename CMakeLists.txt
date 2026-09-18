# 指定 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称（可自定义，比如 BTreeProject）
project(BinaryTree LANGUAGES CXX)

# 设置 C++ 标准为 C++17（可根据需要改为 11 或 14）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件：将这三个源文件编译链接成一个可执行文件
add_executable(BinaryTree
    BinaryTree.cpp
    main.cpp
)