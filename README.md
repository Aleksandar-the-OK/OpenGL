# OpenGL setup Debian (GLFW + CMake + VSC)

## Prerequisites

Make sure you have the required packages:

```bash
sudo apt update
sudo apt install libglfw3-dev libgl1-mesa-dev cmake g++
```
Clone this repository (or copy the files into a folder):

```bash
git clone https://github.com/yourusername/my-opengl-app.git
```
If GlFW is not installed systemwide (by running libglfw3-dev, or if you want to run the latest version
from the git repo above), build and install it:
```bash
cmake -S glfw -B glfw/build
cmake --build glfw/build
sudo cmake --install glfw/build
```
Make a CMakeLists file like below and make sure to have a main file in the desired directory:
```cmake
cmake_minimum_required(VERSION 3.10)
project(ProjectName)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(projectname main.cpp)
target_link_libraries(projectname PRIVATE glfw OpenGL::GL)
```
Open the project in VSC by running ```code .``` in terminal.
Press Control + Shift + P and run CMake: Configure.

If everything was successfull, you can now compile your code pressing the run button in VSC.

## Automatically running the program

In the ``` .vscode ``` directory, create a launch.json file and copy paste the following:
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Run My OpenGL App",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/projectname",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```
So now whenever you press F5 VSC will run your program for you.

# GLAD

In order to skip retrieving function pointers, use the GLAD library. Download the libraries [here](https://glad.dav1d.de/).
Make sure the language is set to C++, and the API set to OpenGL version of at least 3.3, profile set to core and the generate loader box is ticked.
Click generate and download the zip folder.
Add the glad.c file in your project directory together with the include direcotry. 
Example:
```bash
├── glad.c
├── include
│   ├── glad
│   └── KHR
├── main.cpp

```

Add these two lines in cmake and re-run cmake configure in VSC
```cmake
# Add include directory for GLAD
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add executable with your sources
add_executable(projectname main.cpp glad.c)

```
After adding ``` #include <glad/glad.h> ``` and ```#include <GLFW/glfw3.h>``` in your main file, you should be ready to start using OpenGL