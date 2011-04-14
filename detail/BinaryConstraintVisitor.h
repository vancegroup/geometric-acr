/** @file BinaryConstraintVisitor.h
	@brief The core of automatic constraint recognition - contains a binary
	visitor for the boost::variant-based BoundaryFeature type, and function
	template specializations for each feature pair that indicates a constraint.

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
#include "../BoundaryFeatures.h"

// Library/third-party includes
#include <boost/variant/static_visitor.hpp>

// Standard includes
#include <iostream>

namespace boundary_features {
	namespace detail {
		class BinaryConstraintVisitor;

		/** @brief Evaluate any two boundary feature types, returning true and
			update the constraint visitor iff the collision of the two features
			imply a constraint.

			A default, templated implementation exists as a fallback to indicate
			"no constraint" for pairs which do not result in a recognized constraint.

			To recognize new constraints, provide a function template specialization
			of this function that returns "true" and updates the visitor accordingly.

			@note Remember that feature types may be presented in either order -
			implementing accumulateConstraint<A, B>() doesn't automatically create
			accumulateConstraint<A, B>()
		*/
		template<typename T, typename U>
		bool accumulateConstraint(BinaryConstraintVisitor & /*visitor*/, const T& lhs, const U& rhs) {
			std::cout << "No constraint!" << std::endl << std::endl;
			return false;
		}

		/// Binary static visitor for accumulating constraints generated between
		/// one or more pairs of constraints, using boost::apply_visitor.
		/// Invokes accumulateConstraint() with the types of features.
		class BinaryConstraintVisitor : public boost::static_visitor<> {
			public:
				/// Default constructor
				BinaryConstraintVisitor() : constraints(0) {}

				/// Templated function-call operator for static_visitor compatibility,
				/// calling accumulateConstraint() with the same template parameters.
				template<typename T, typename U>
				void operator()(const T& lhs, const U& rhs) {
					std::cout << "Left: name=" << lhs.name << std::endl;
					std::cout << "Right: name=" << rhs.name << std::endl;

					accumulateConstraint(*this, lhs, rhs);
				}

				/// The number of constraints recognized: updated by specializations
				/// of accumulateConstraint()
				int constraints;

		};

		//--  Specializations of accumulateConstraint() Follow --//
		template<>
		bool accumulateConstraint<Circle, Cylinder>(BinaryConstraintVisitor & visitor, const Circle& lhs, const Cylinder& rhs) {
			std::cout << "Got a concentric constraint! (circle, cylinder)" << std::endl << std::endl;
			visitor.constraints++;
			return true;
		}

		template<>
		bool accumulateConstraint<Cylinder, Circle>(BinaryConstraintVisitor & visitor, const Cylinder& lhs, const Circle& rhs) {
			std::cout << "Got a reverse-order concentric constraint! (cylinder, circle)" << std::endl << std::endl;
			visitor.constraints++;
			return true;
		}
	} // end of namespace detail
} // end of namespace boundary_features

#endif // INCLUDED_BinaryConstraintVisitor_h_GUID_bebf5397_c20c_47c2_b4c1_5c1cd29e06fd
