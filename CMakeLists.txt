cmake_minimum_required(VERSION 3.16.0)
project(ORT_YOLOv5)
set(CMAKE_PROJECT_VERSION_MAJOR 0)
set(CMAKE_PROJECT_VERSION_MINOR 1)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_APPLE_SILICON_PROCESSOR arm64)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_VERBOSE_MAKEFILE True)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(OUTPUT_ELF ${CMAKE_PROJECT_NAME}_v${CMAKE_PROJECT_VERSION_MAJOR}${CMAKE_PROJECT_VERSION_MINOR}_${CMAKE_BUILD_TYPE} )

if(MSVC)
    include(dependency_msvc.cmake)
else()
    include(dependency.cmake)
endif(MSVC)

set(SRC_FILES
        ./src/main.cpp
        ./src/detector.cpp
        ./src/utils.cpp
        )

add_executable(${OUTPUT_ELF} ${SRC_FILES})
target_include_directories(${OUTPUT_ELF} PRIVATE
        inc
        ${DEP_INCLUDE_DIRS}
        )
target_link_directories(${OUTPUT_ELF} PRIVATE
        ${DEP_LIBRARY_DIRS}
        )
target_link_libraries(${OUTPUT_ELF} PRIVATE
        ${DEP_LIBRARIES}
        )
target_compile_definitions(${OUTPUT_ELF} PRIVATE
        PROJECT_SRC_DIR="${PROJECT_SOURCE_DIR}"
        )

if(MSVC)
    target_compile_definitions(${OUTPUT_ELF} PUBLIC -W4)
else()
    target_compile_options(${OUTPUT_ELF} PUBLIC -Wall -O3)
endif(MSVC)
