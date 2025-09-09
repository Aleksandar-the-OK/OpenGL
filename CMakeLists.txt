cmake_minimum_required(VERSION 3.10)
project(testis)

set(CMAKE_CXX_STANDARD 17)

# Add include directory for GLAD
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add executable with your sources
add_executable(testis main.cpp glad.c)

# Link GLFW (make sure you have it installed)
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(testis glfw)
# On Linux you also need to link dl and pthread
if(UNIX)
    target_link_libraries(testis dl pthread)
endif()





cmake_minimum_required(VERSION 3.10)
project(ProjectName)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(projectname main.cpp)
target_link_libraries(projectname PRIVATE glfw OpenGL::GL)