# CMakeList.txt : CMake project for StoreApps, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


add_executable(StoreProject StoreProject.cpp)


target_link_libraries(StoreProject PUBLIC Server)


if(NOT DEFINED CMAKE_INSTALL_PREFIX OR CMAKE_INSTALL_PREFIX MATCHES "")
  set(CMAKE_INSTALL_PREFIX  ".")
endif()


install(TARGETS StoreProject Server DESTINATION  ${CMAKE_CURRENT_LIST_DIR})

add_custom_target(run
    COMMAND StoreProject
    DEPENDS StoreProject
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

# TODO: Add tests and install targets if needed.
