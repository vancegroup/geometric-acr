# 2009-2011 Ryan Pavlik <rpavlik@iastate.edu>
# http://academic.cleardefinition.com/
# Iowa State University HCI Graduate Program/VRAC

set(SOURCES
	testapp.cpp
	Circle.cpp
	Constraint.cpp
	Cylinder.cpp
	Plane.cpp
	RecognizeConstraints.cpp)

set(HEADERS
	BoundaryFeatures_fwd.h
	BoundaryFeatures.h
	Circle.h
	Constraint.h
	Cylinder.h
	Plane.h
	RecognizeConstraints.h)

set(DETAIL_HEADERS
	detail/RecognizedPairs/CircleCylinder.h

	detail/accumulateConstraint.h
	detail/BinaryConstraintVisitor.h
	detail/ConstraintFromFeaturePair.h
	detail/ConstraintFromFeaturePair_fwd.h
	detail/IsRecognized.h)

#add_library(sparta-bfeat STATIC ${SOURCES} ${HEADERS} ${DETAIL_HEADERS})
add_executable(sparta-bfeat ${SOURCES} ${HEADERS} ${DETAIL_HEADERS})

add_cppcheck(sparta-bfeat STYLE FAIL_ON_WARNING)

