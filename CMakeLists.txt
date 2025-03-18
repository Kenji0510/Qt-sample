cmake_minimum_required(VERSION 3.16)
project(QtWindowExample)

# set(CMAKE_PREFIX_PATH "/home/kenji/Qt/6.8.2/gcc_64/lib/cmake")

set(CMAKE_AUTOMOC ON)

# Qt6 のパッケージを探す
find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGL OpenGLWidgets)

find_package(OpenGL REQUIRED)

find_package(GLEW REQUIRED)

# 実行ファイルの設定
add_executable(QtWindowExample 
src/main.cpp 
src/mainwindow.cpp 
src/subwindow.cpp
src/openglsample.cpp
)

# Qt6 をリンクする
target_link_libraries(QtWindowExample 
Qt6::Widgets
Qt6::OpenGL
Qt6::OpenGLWidgets
OpenGL::GL
GLEW::GLEW
)
