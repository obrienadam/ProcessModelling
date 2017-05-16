cmake_minimum_required (VERSION 3.0.2)
project (ProcessModelling)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the QtCore and Qt5Widgets library
find_package(Qt5 REQUIRED Widgets Designer)

set(QT_USE_QTDESIGNER true)

# Linear algebra
find_package(Armadillo REQUIRED)

# Add all of the other directories to include
include_directories(src/ProcessModel)
include_directories(src/ProcessModel/Blocks)
include_directories(src/ProcessModel/LinearAlgebra)
include_directories(src/ProcessModel/Model)
include_directories(src/ProcessModelScene)

# Compiler setup
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
add_subdirectory(app)
