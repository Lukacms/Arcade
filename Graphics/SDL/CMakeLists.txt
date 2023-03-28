##
## CMakeLists: Graphics/SDL
##

add_library(
  arcade_sdl2 SHARED
  src/sdl.cpp
  src/SDLWindow.cpp
  src/SDLDisplay.cpp
  src/entities/SDLSprite.cpp
  src/entities/SDLText.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(arcade_sdl2 PRIVATE include)
target_compile_options(arcade_sdl2 PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade_sdl2 PRIVATE arcade-interface)
set_property(TARGET arcade_sdl2 PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade_sdl2 PROPERTY CXX_STANDARD_REQUIRED ON)
