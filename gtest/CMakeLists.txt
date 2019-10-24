cmake_minimum_required (VERSION 3.6)

project (testJoey)

# Add source dir
include_directories (../src)

## In case you have gtest installed already you can use the following to locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# For glib
find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)

##################################
# Download and install GoogleTest if one day we do not want to have it pre-installed
# include(ExternalProject)
# ExternalProject_Add(gtest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG release-1.10.0
#   PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
#   INSTALL_COMMAND ""
# )
# ExternalProject_Get_Property(gtest source_dir binary_dir)

################
# Link runUnitTests with what we want to test and the GTest and pthread library
file(GLOB TEST_FILES_SOURCES "*.cpp")
file(GLOB C_FILES_SOURCES "../src/*.c")
add_executable(runUnitTests ${TEST_FILES_SOURCES} ${C_FILES_SOURCES})
target_include_directories(runUnitTests PRIVATE ${GLIB_INCLUDE_DIRS})
target_link_libraries(runUnitTests ${GTEST_LIBRARIES} pthread ${GLIB_LDFLAGS})

######################################
# Configure the test to use GoogleTest
# add_dependencies(runUnitTests gtest)
# include_directories(${source_dir}/include)
# target_link_libraries(runUnitTests ${binary_dir}/libgtest.a)
# target_link_libraries(runUnitTests ${binary_dir}/libgtest_main.a)

##################################
# Just make the test runnable with
#   $ make test
enable_testing()
add_test(runUnitTests runUnitTests)
