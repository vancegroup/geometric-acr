# 2009-2011 Ryan Pavlik <rpavlik@iastate.edu>
# http://academic.cleardefinition.com/
# Iowa State University HCI Graduate Program/VRAC

set(SOURCES
	BinaryConstraintVisitor.cpp
	BinaryConstraintVisitor.h
	BoundaryFeatures.cpp
	BoundaryFeatures.h
	Circle.cpp
	Circle.h
	Cylinder.cpp
	Cylinder.h
	Plane.cpp
	Plane.h)

#add_library(sparta-bfeat STATIC ${SOURCES})
add_executable(sparta-bfeat ${SOURCES})

add_cppcheck(sparta-bfeat STYLE FAIL_ON_WARNING)

