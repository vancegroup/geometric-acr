/**
	@file BinaryConstraintVisitor.cpp
	@brief

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

// Internal Includes
#include "RecognizeConstraints.h"
#include "BoundaryFeatures.h"

// Library/third-party includes
// - none

// Standard includes
#include <iostream>

using namespace boundary_features;

int main() {
	Circle circle;
	Cylinder cylinder;
	Plane plane;

	FeatureSet a;
	a.insert(circle);
	a.insert(plane);

	FeatureSet b;
	b.insert(plane);
	b.insert(cylinder);

	int constraints = recognizeConstraints(a, b);
	std::cout << "Found a total of " << constraints << " constraints" << std::endl;

	return 0;
}
