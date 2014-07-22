cmake_minimum_required(VERSION 2.6.2)

# Set package properties
project(boundaryfeatures)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CTest)

include(SetDefaultBuildType)
set_default_build_type(RelWithDebInfo)

option(BUILD_TIMING "Should we build the many timing executables?" off)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/vendor/eigen-3.2.1")

add_subdirectory(boundary_features)

if(BUILD_TESTING)
	add_executable(bfeat-testapp testapp.cpp)
	target_link_libraries(bfeat-testapp bfeat)

	add_subdirectory(tests)
endif()

if(BUILD_TIMING)
    add_subdirectory(timing)
endif()


