##
## CMakeLists: Games/Snake
##

add_library(
  arcade_snake SHARED
  src/Snake.cpp
  src/SnakeGame.cpp
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(arcade_snake PRIVATE include)
target_compile_options(arcade_snake PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade_snake PRIVATE arcade-interface)
set_property(TARGET arcade_snake PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade_snake PROPERTY CXX_STANDARD_REQUIRED ON)
