##
## CMakeLists: Games/Nibbler
##

add_library(
  arcade_nibbler SHARED
  src/Nibbler.cpp
  src/EntryPoint.cpp
  src/NibblerGame.cpp
  src/NibblerInitGame.cpp
  src/ClockNibbler.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(arcade_nibbler PRIVATE include)
target_compile_options(arcade_nibbler PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade_nibbler PRIVATE arcade-interface)
set_property(TARGET arcade_nibbler PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade_nibbler PROPERTY CXX_STANDARD_REQUIRED ON)
