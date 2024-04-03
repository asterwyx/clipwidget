cmake_minimum_required(VERSION 3.5)

project(clipwidget VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(PREFER_QT5 "Prefer qt5" ON)

if (PREFER_QT5)
    set(QT_VERSION_MAJOR 5)
else()
    set(DTK_VERSION 6)
    set(QT_VERSION_MAJOR 6)
endif()

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Dtk${DTK_VERSION} COMPONENTS Core Widget REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(clipwidget
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET clipwidget APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(clipwidget SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(clipwidget
            ${PROJECT_SOURCES}
            customwidget.h customwidget.cpp
            dclipeffectwidget.h dclipeffectwidget.cpp
        )
    endif()
endif()

target_link_libraries(clipwidget PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::WidgetsPrivate Dtk${DTK_VERSION}::Core Dtk${DTK_VERSION}::Widget)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(clipwidget)
endif()
