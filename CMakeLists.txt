# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("StoreApps")

# Set C++ 17 Standard
set(CMAKE_CXX_STANDARD 17)

# Include sub-projects.
add_subdirectory ("StoreLibrary")
add_subdirectory ("StoreProject")

if(NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE MATCHES "")
  set(CMAKE_BUILD_TYPE  debug)
endif()


