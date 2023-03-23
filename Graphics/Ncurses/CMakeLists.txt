##
## CMakeLists: Graphics/Ncurses
##

add_library(
  arcade_ncurses SHARED
  src/ncurses.cpp
  src/NCursesDisplay.cpp
  src/NCursesWindow.cpp
  src/entities/NCursesSprite.cpp
  src/entities/NCursesText.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

target_include_directories(arcade_ncurses PRIVATE include)
target_compile_options(arcade_ncurses PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade_ncurses PRIVATE arcade-interface)
set_property(TARGET arcade_ncurses PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade_ncurses PROPERTY CXX_STANDARD_REQUIRED ON)
