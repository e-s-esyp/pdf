cmake_minimum_required(VERSION 3.31)
project(pdf)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Qml
        Quick
        Widgets
        REQUIRED)

add_executable(pdf main.cpp
        qml.qrc
)
target_link_libraries(pdf
        Qt5::Core
        Qt5::Gui
        Qt5::Qml
        Qt5::Quick
        Qt5::Widgets
)

