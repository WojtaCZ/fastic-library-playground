set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
cmake_minimum_required(VERSION 3.6.0)
#adjust your project name here
#then please adjust binary (elf) names in launch.json accordingly
project(aurora LANGUAGES CXX C ASM VERSION 0.1.0)


set(CMAKE_COLOR_MAKEFILE FALSE)
set(CMAKE_COLOR_DIAGNOSTICS FALSE)



#base path for sources
set(SOURCE_BASE ${CMAKE_SOURCE_DIR}/src)


set(SOURCES
	${SOURCE_BASE}/main.cpp
	${CMAKE_SOURCE_DIR}/fastic-library/src/aurora.cpp
	#${SOURCE_BASE}/fastic.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})


set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23)
set_target_properties(${PROJECT_NAME} PROPERTIES C_STANDARD 11)

target_include_directories(${PROJECT_NAME} PRIVATE
	${SOURCE_BASE}
	${CMAKE_SOURCE_DIR}/fastic-library/inc
	${CMAKE_SOURCE_DIR}/src/
)
