##
## CMakeLists: Graphics / SFML
##

add_library(
  arcade_sfml SHARED
  src/SFML.cpp
  src/SFMLWindow.cpp
  src/SFMLDisplay.cpp
  src/entities/SFMLSprite.cpp
  src/entities/SFMLText.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(arcade_sfml PRIVATE include)
target_compile_options(arcade_sfml PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade_sfml PRIVATE arcade-interface sfml-graphics sfml-window)
set_property(TARGET arcade_sfml PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade_sfml PROPERTY CXX_STANDARD_REQUIRED ON)
