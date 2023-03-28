##
## CMakeLists: Arcade / Arcade
##

cmake_minimum_required(VERSION 3.16)

# standard version cpp
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# project name
project(arcade)

# change library prefix to none
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# for library compilation => shared libraries of games and graphics
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# include directories
include_directories(Core/include/)

# add a subdirectory to compile, to uncomment when CMakeLists will be complete
add_subdirectory(Games)
add_subdirectory(Graphics)

# Warning flags
set(GCC_WARNING_FLAGS
    -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches
    -Wlogical-op -Wnull-dereference -Wuseless-cast -fno-gnu-unique)

set(CLANG_WARNING_FLAGS
    -Weverything
    -Wno-c++20-compat
    -Wno-c++98-c++11-compat-binary-literal
    -Wno-c++98-compat
    -Wno-c++98-compat-pedantic
    -Wno-c99-extensions
    -Wno-disabled-macro-expansion
    -Wno-documentation-unknown-command
    -Wno-exit-time-destructors
    -Wno-global-constructors
    -Wno-implicit-int-float-conversion
    -Wno-return-std-move
    -Wno-return-type-c-linkage
    -Wno-signed-enum-bitfield
    -Wno-weak-vtables)

if(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 13.0.0)
  set(CLANG_WARNING_FLAGS ${CLANG_WARNING_FLAGS} -Wno-return-std-move-in-c++11)
endif()

set(WARNING_FLAGS
    -Wall
    -Wextra
    -Wshadow
    -Wnon-virtual-dtor
    -pedantic
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Woverloaded-virtual
    -Wpedantic
    -Wconversion
    -Wsign-conversion
    -Wdouble-promotion
    -Wformat=2
    -Weffc++
    -Wno-padded
    -Wno-ctad-maybe-unsupported)

# set different flags
set(CMAKE_BUILD_TYPE
    ${CMAKE_BUILD_TYPE}
    CACHE
      STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel tsan"
      FORCE)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")
endif()

# Clang-tidy
if(USE_CLANG_TIDY)
  find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy"
    DOC "Path to clang-tidy executable")
  if(CLANG_TIDY_EXE)
    if(DEFINED arcade_CLANG_TIDY_FLAGS)
      set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}"
                               "${arcade_CLANG_TIDY_FLAGS}")
    else()
      set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()
    message("-- Found clang-tidy: ${CLANG_TIDY_EXE}")
  else()
    message("-- Failed to find clang-tidy")
  endif()
endif()

# set warning flags
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(WARNING_FLAGS ${WARNING_FLAGS} ${CLANG_WARNING_FLAGS})
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(WARNING_FLAGS ${WARNING_FLAGS} ${GCC_WARNING_FLAGS})
else()
  error("${CMAKE_CXX_COMPILER_ID}: Unsupported compiler.")
endif()

add_library(arcade-interface INTERFACE)

# link shared libraries and compile them
# do not uncomment commented lines, just for personnal comprehension
set_property(TARGET arcade-interface PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade-interface PROPERTY CXX_STANDARD_REQUIRED ON)

# adding executables
add_executable(
    arcade
    Core/src/ADisplay.cpp
    Core/src/main.cpp
    Core/src/core/Core.cpp
    Core/src/core/libsMethods.cpp
    Core/src/opts/Opts.cpp
    Core/src/opts/libFactory.cpp
    )

# rules for arcade project
target_link_libraries(
    arcade
    arcade-interface
    )
target_link_options(arcade PRIVATE -rdynamic)
target_compile_options(arcade PRIVATE ${WARNING_FLAGS})
set_property(TARGET arcade PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade PROPERTY CXX_STANDARD_REQUIRED ON)
