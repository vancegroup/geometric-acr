# CMake cross-platform build system
# 2009-2010 Ryan Pavlik <rpavlik@iastate.edu>
# http://academic.cleardefinition.com/
# Iowa State University HCI Graduate Program/VRAC

include(BoostTestTargets)
add_boost_test(boundary_features
	SOURCES
	test_boundary_features.cpp
	LIBRARIES
	sparta-bfeat)

add_executable(bfeat_timing timing.cpp)
target_link_libraries(bfeat_timing sparta-bfeat)
