/**
	@file RecognizeConstraints.cpp
	@brief Implementation of constraint recognition wrapper function.

	The actual work is done in BinaryConstraintVisitor.h - the function in
	this file mostly exists to keep that header internal and present a nicer
	API: two feature sets go in, results come out, and how it happens doesn't
	matter.

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
#include "detail/BinaryConstraintVisitor.h"

// Library/third-party includes
#include <boost/variant/apply_visitor.hpp>

// Standard includes
// - none

namespace boundary_features {
	int recognizeConstraints(FeatureSet const & a, FeatureSet const& b) {
		detail::BinaryConstraintVisitor visitor;
		for (FeatureSet::const_iterator itA = a.begin(); itA != a.end(); ++itA) {
			for (FeatureSet::const_iterator itB = b.begin(); itB != b.end(); ++itB) {
				boost::apply_visitor(visitor, *itA, *itB);
			}
		}
		return visitor.constraints;
	}
} // end of namespace boundary_features
