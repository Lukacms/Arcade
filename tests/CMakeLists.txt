##
## CMakeLists: tests / tests
##

cmake_minimum_required(VERSION 3.6)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/)

# Source files
set(
    SRCS
)

# binary
add_executable(tests-arcade ${SRCS})
target_include_directories(tests-arcade PRIVATE utils)
target_link_libraries(tests-arcade arcade-core Catch2)
set_property(TARGET tests-arcade PROPERTY CXX_STANDARD 20)
set_property(TARGET tests-arcade PROPERTY CXX_STANDARD_REQUIRED ON)
