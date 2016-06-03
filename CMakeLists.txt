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

        #Collision
        Project3D/Objects/Collision/CollisionBox.cpp

        #Controls
        Project3D/Controls/GameController.cpp
        Project3D/Controls/keyboard/KeyboardController.cpp

        #sound
        irrKlang-1.5.0/64/include/irrKlang.h
        irrKlang-1.5.0/64/include/ik_ISound.h
        irrKlang-1.5.0/64/include/ik_ISoundSource.h
        irrKlang-1.5.0/64/include/ik_ESoundEngineOptions.h
        irrKlang-1.5.0/64/include/ik_ESoundOutputDrivers.h
        irrKlang-1.5.0/64/include/ik_EStreamModes.h
        irrKlang-1.5.0/64/include/ik_IAudioStream.h
        irrKlang-1.5.0/64/include/ik_IAudioStreamLoader.h
        irrKlang-1.5.0/64/include/ik_IAudioRecorder.h
        irrKlang-1.5.0/64/include/ik_IFileReader.h
        irrKlang-1.5.0/64/include/ik_IFileFactory.h
        irrKlang-1.5.0/64/include/ik_irrKlangTypes.h
        irrKlang-1.5.0/64/include/ik_ISoundEngine.h
        irrKlang-1.5.0/64/include/ik_IRefCounted.h
        irrKlang-1.5.0/64/include/ik_ISoundMixedOutputReceiver.h
        irrKlang-1.5.0/64/include/ik_ISoundStopEventReceiver.h
        irrKlang-1.5.0/64/include/ik_IVirtualRefCounted.h
        irrKlang-1.5.0/64/include/ik_SAudioStreamFormat.h
        irrKlang-1.5.0/64/include/ik_SAudioStreamFormat.h
        irrKlang-1.5.0/64/include/ik_vec3d.h
        irrKlang-1.5.0/64/include/ik_ISoundDeviceList.h
        irrKlang-1.5.0/64/include/ik_ISoundEffectControl.h

        Project3D/SoundPlayer.cpp

        #logic
        Project3D/logic.cpp

        #gameobjects
        Project3D/GameObject.cpp
        Project3D/Object.cpp

        #models
        Project3D/Objects/ObjModel.cpp

        #Node
        Project3D/Objects/node/Node.cpp

        #skybox
        Project3D/Skybox.cpp
        )

add_executable(Menghindar_Diri ${SOURCE_FILES})
include_directories(/irrKlang-1.5.0/64/include/)

#glut and OpenGl
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(Menghindar_Diri ${OPENGL_LIBRARIES} ${GLUT_LIBRARY}
        ${CMAKE_SOURCE_DIR}/irrKlang-1.5.0/__MACOSX/irrklang-1.5.0/lib/libikpFLAC.dylib
        ${CMAKE_SOURCE_DIR}/irrKlang-1.5.0/__MACOSX/irrklang-1.5.0/lib/libikpMP3.dylib
        ${CMAKE_SOURCE_DIR}/irrKlang-1.5.0/__MACOSX/irrklang-1.5.0/lib/libirrklang.dylib
        )

