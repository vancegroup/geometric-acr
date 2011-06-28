# 2009-2011 Ryan Pavlik <rpavlik@iastate.edu>
# http://academic.cleardefinition.com/
# Iowa State University HCI Graduate Program/VRAC

set(SOURCES
	Circle.cpp
	Cone.cpp
	Constraint.cpp
	Cylinder.cpp
	CylindricalConstraint.cpp
	GeometricConstraint.cpp
	Plane.cpp
	RecognizeConstraints.cpp
	Sphere.cpp)

set(HEADERS
	BoundaryFeatures_fwd.h
	BoundaryFeatures.h
	Circle.h
	Cone.h
	Constraint.h
	Cylinder.h
	CylindricalConstraint.h
	GeometricConstraint.h
	Plane.h
	RecognizeConstraints.h
	Sphere.h)

set(DETAIL_HEADERS
	detail/RecognizedPairs/CircleCylinder.h
	detail/RecognizedPairs/ConeCone.h
	detail/RecognizedPairs/CylinderCylinder.h
	detail/RecognizedPairs/PlanePlane.h
	detail/RecognizedPairs/SphereCylinder.h
	detail/RecognizedPairs/SphereSphere.h

	detail/accumulateConstraint.h
	detail/BinaryConstraintVisitor.h
	detail/ConstraintFromFeaturePair.h
	detail/ConstraintFromFeaturePair_fwd.h
	detail/IsRecognized.h)

add_library(sparta-bfeat STATIC ${SOURCES} ${HEADERS} ${DETAIL_HEADERS})

add_cppcheck(sparta-bfeat STYLE FAIL_ON_WARNING)

if(BUILD_TESTING)
	add_executable(sparta-bfeat-testapp testapp.cpp)
	target_link_libraries(sparta-bfeat-testapp sparta-bfeat)

	add_subdirectory(tests)
endif()
