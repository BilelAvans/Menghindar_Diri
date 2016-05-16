cmake_minimum_required(VERSION 3.5)
project(Menghindar_Diri)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
#    freeglut/include/GL/freeglut.h
#    freeglut/include/GL/freeglut_ext.h
#    freeglut/include/GL/freeglut_std.h
#    freeglut/include/GL/glut.h
#    freeglut/Copying.txt
#    freeglut/Readme.txt
#    glew-1.11.0/include/GL/glew.h
#    glew-1.11.0/include/GL/glxew.h
#    glew-1.11.0/include/GL/wglew.h
        Project3D/main.cpp
        Project3D/Character.cpp
        Project3D/Model_OBJ.cpp
        Project3D/ModelObject.cpp
        Project3D/Model_OBJ.h
        Project3D/ShapeCalculator.h
        Project3D/Player.cpp
        )

add_executable(Menghindar_Diri ${SOURCE_FILES})

#glut and OpenGl
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(Menghindar_Diri ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

