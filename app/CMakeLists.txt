# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

include_directories(libs/libpng/jni
                    libs/glm-0.9.8.5
                    libs/rapidjson/include
                    libs/freetype-2.9/include
                    )

add_subdirectory(libs/libpng)
add_subdirectory(libs/glm-0.9.8.5)
add_subdirectory(libs/rapidjson)
add_subdirectory(libs/freetype-2.9)

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp
             src/main/cpp/game.h
             src/main/cpp/game.cpp
             src/main/cpp/shader.h
             src/main/cpp/shader.cpp
             src/main/cpp/resource_manager.h
             src/main/cpp/resource_manager.cpp
             src/main/cpp/texture.h
             src/main/cpp/texture.cpp
             src/main/cpp/sprite_renderer.h
             src/main/cpp/sprite_renderer.cpp
             src/main/cpp/game_object.h
             src/main/cpp/game_object.cpp
             src/main/cpp/game_level.h
             src/main/cpp/game_level.cpp
             src/main/cpp/ball_object.h
             src/main/cpp/ball_object.cpp
             src/main/cpp/particle_generator.h
             src/main/cpp/particle_generator.cpp
             src/main/cpp/post_processor.h
             src/main/cpp/post_processor.cpp
             src/main/cpp/reward.h
             src/main/cpp/reward.cpp
             src/main/cpp/text_renderer.h
             src/main/cpp/text_renderer.cpp
             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              #log-lib
              android-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log
              )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       #${log-lib}
                       -llog
                       #${android-lib}
                       GLESv2
                       android
                       png
                       z
                       glm
                       freetype
                       )