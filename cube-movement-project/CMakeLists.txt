cmake_minimum_required(VERSION 3.16) 
project(CubeMovement) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 


# Find required packages 
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED) 
find_package(PkgConfig REQUIRED) 


# Find SOIL (Simple OpenGL Image Library) 
pkg_check_modules(SOIL REQUIRED soil) 


# Include directories 
include_directories(include) 
include_directories(${GLEW_INCLUDE_DIRS}) 

set (SOURCES 
	src/main.cpp
	src/Shader.cpp
	src/Camera.cpp
	src/Cube.cpp
	src/Renderer.cpp
	src/InputHandler.pp
	src/TextureLoader.cpp
)


# Create executable 
add_executable(${PROJECT_NAME} ${SOURCES}) 

# Link Libraries 
target_link_libraries(${PROJECT_NAME} 
	glfw
	${GLEW_LIBRARIES}
	GL
	${SOIL_LIBRARIES}
)

# Compiler flags 
target_compile_options(${PROJECT_NAME} PRIVATE ${GLEW_CFLAGS_OTHER})


# Copy shaders and textures to build directory 
file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})
file(COPY textures DESTINATION ${CMAKE_BINARY_DIR}) 



