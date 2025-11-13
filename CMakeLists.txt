cmake_minimum_required(VERSION 3.31)
project(pdfProject)

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
qt5_wrap_cpp(MAIN_MOC main.cpp)
add_executable(${PROJECT_NAME}
        main.cpp
        qml.qrc
        pdfwidgets/qpdfview.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/pdf
        ${CMAKE_CURRENT_SOURCE_DIR}/pdf/api
)
target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Qml
        Qt5::Quick
        Qt5::Widgets
)

