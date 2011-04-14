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
	FeatureSet s;
	s.insert(cylinder);
	s.insert(plane);
	
	BoundaryFeature c(circle);
	BinaryConstraintVisitor visitor;
	for (FeatureSet::iterator it = s.begin(); it != s.end(); ++it) {
		boost::apply_visitor(visitor, c, *it);
	}
		
	return 0;
}
