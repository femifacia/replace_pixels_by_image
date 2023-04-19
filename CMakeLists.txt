cmake_minimum_required(VERSION 3.17)

set(BINARY_NAME "replace_pixel_by_image")

project( ${BINARY_NAME} )

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


FILE(GLOB SRC_FILES  ./src/main.cpp
                        ./src/ImageManager/ImageManager.cpp
                        ./src/ImageException/ImageException.cpp
        )


#set (CMAKE_AUTOMOC ON)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( ${BINARY_NAME} ${SRC_FILES} )

target_link_libraries( ${BINARY_NAME} ${OpenCV_LIBS} )