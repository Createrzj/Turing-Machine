cmake_minimum_required(VERSION 3.28)
project(Turing_Machine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/Qt5.14.2/Tools/mingw730_64")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Turing_Machine main.cpp
        src/turing.cpp
        include/turing.h
        ui/turing.ui
        src/QuickSort.cpp
        include/QuickSort.h
        include/Library.h
        include/Inter_BinarySer.h
        src/Inter_BinarySer.cpp
        src/main_interface.cpp
        include/main_interface.h
        ui/main_interface.ui
        src/Recur_BinarySer.cpp
        include/Recur_BinarySer.h
        src/knapsack.cpp
        include/knapsack.h
        ui/knapsack.ui
        src/DP_knap.cpp
        include/DP_knap.h
        src/Memory_knap.cpp
        include/Memory_knap.h
        src/recur_knapsack.cpp
        include/recur_knapsack.h
        ui/recur_knapsack.ui
)
target_link_libraries(Turing_Machine
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
    endforeach (QT_LIB)
endif ()
