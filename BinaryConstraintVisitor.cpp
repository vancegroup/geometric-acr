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
#include "BinaryConstraintVisitor.h"

// Library/third-party includes
#include <boost/variant/apply_visitor.hpp>

// Standard includes
// - none

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

	BoundaryFeature c(circle);
	BinaryConstraintVisitor visitor;
	for (FeatureSet::iterator itA = a.begin(); itA != a.end(); ++itA) {
		for (FeatureSet::iterator itB = b.begin(); itB != b.end(); ++itB) {
			boost::apply_visitor(visitor, *itA, *itB);
		}
	}
	std::cout << "Found a total of " << visitor.constraints << " constraints" << std::endl;

	return 0;
}
