
set(SOURCES
	Circle.cpp
	Cone.cpp
	ConstraintSet.cpp
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
	ConstraintSet.h
	Cylinder.h
	CylindricalConstraint.h
	GeometricConstraint.h
	GeometricConstraint_fwd.h
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

add_library(bfeat STATIC ${SOURCES} ${HEADERS} ${DETAIL_HEADERS})

