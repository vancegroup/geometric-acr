/** @file BinaryConstraintVisitor.h
	@brief The core of automatic constraint recognition - contains a binary
	visitor for the boost::variant-based BoundaryFeature type, which dispatches
	to the overloaded accumulateConstraint() function.

	Used within RecognizeConstraints.cpp - should not need to be included
	by "user" code.

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef INCLUDED_BinaryConstraintVisitor_h_GUID_bebf5397_c20c_47c2_b4c1_5c1cd29e06fd
#define INCLUDED_BinaryConstraintVisitor_h_GUID_bebf5397_c20c_47c2_b4c1_5c1cd29e06fd

// Internal Includes
#include "accumulateConstraint.h"
#include "../RecognizeConstraints.h"

// Library/third-party includes
#include <boost/variant/static_visitor.hpp>

// Standard includes
// - none

namespace boundary_features {
	namespace detail {

		/// Binary static visitor for accumulating constraints generated between
		/// one or more pairs of constraints, using boost::apply_visitor.
		/// Invokes accumulateConstraint() with the types of features.
		class BinaryConstraintVisitor : public boost::static_visitor<> {
			public:
				/// Default constructor
				BinaryConstraintVisitor() {}

				/// Templated function-call operator for static_visitor compatibility,
				/// calling accumulateConstraint() with the same template parameters.
				template<typename T, typename U>
				void operator()(const T& lhs, const U& rhs) {
					c.pairsChecked++;
					ConstraintPtr ret = accumulateConstraint(lhs, rhs);
					if (ret) {
						c.constraintsRecognized.insert(ret);
					}
				}

				RecognizedConstraints c;

		};
	} // end of namespace detail
} // end of namespace boundary_features

#endif // INCLUDED_BinaryConstraintVisitor_h_GUID_bebf5397_c20c_47c2_b4c1_5c1cd29e06fd
