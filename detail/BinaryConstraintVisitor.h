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

		struct UnrecognizedFeaturePair {
			typedef void unrecognized_tag;
		};

		template<typename T, typename U>
		struct ConstraintFromFeaturePair : UnrecognizedFeaturePair {};

		template<typename T, typename U, typename Enable = void>
		struct IsRecognized {
			typedef void type;
		};

		template<typename T, typename U>
		struct IsRecognized<T, U, typename ConstraintFromFeaturePair<T, U>::unrecognized_tag> {};

		template<typename T, typename U, typename Enable = void>
		struct NotRecognized {};

		template<typename T, typename U>
		struct NotRecognized<T, U, typename ConstraintFromFeaturePair<T, U>::unrecognized_tag> {
			typedef void type;
		};
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
		bool accumulateConstraint(BinaryConstraintVisitor & /*visitor*/,
		                          const T& /*lhs*/,
		                          const U& /*rhs*/,
		                          typename NotRecognized<T, U>::type* = 0,
		                          typename NotRecognized<U, T>::type* = 0) {
			return false;
		}

		template<typename T, typename U>
		bool accumulateConstraint(BinaryConstraintVisitor & visitor,
		                          const T& lhs,
		                          const U& rhs,
		                          typename IsRecognized<T, U>::type* = 0,
		                          typename NotRecognized<U, T>::type* = 0) {
			return ConstraintFromFeaturePair<T, U>::accumulateConstraint(lhs, rhs, false);
		}
		template<typename T, typename U>
		bool accumulateConstraint(BinaryConstraintVisitor & visitor,
		                          const T& lhs,
		                          const U& rhs,
		                          typename NotRecognized<T, U>::type* = 0,
		                          typename IsRecognized<U, T>::type* = 0) {
			return ConstraintFromFeaturePair<U, T>::accumulateConstraint(rhs, lhs, true);
		}

		template<typename T>
		bool accumulateConstraint(BinaryConstraintVisitor & visitor,
		                          const T& lhs,
		                          const T& rhs,
		                          typename IsRecognized<T, T>::type* = 0) {
			return ConstraintFromFeaturePair<T, T>::accumulateConstraint(lhs, rhs, false);
		}

		/// Binary static visitor for accumulating constraints generated between
		/// one or more pairs of constraints, using boost::apply_visitor.
		/// Invokes accumulateConstraint() with the types of features.
		class BinaryConstraintVisitor : public boost::static_visitor<> {
			public:
				/// Default constructor
				BinaryConstraintVisitor() : pairs(0), constraints(0) {}

				/// Templated function-call operator for static_visitor compatibility,
				/// calling accumulateConstraint() with the same template parameters.
				template<typename T, typename U>
				void operator()(const T& lhs, const U& rhs) {
					pairs++;
					std::cout << "(" << lhs.name << ", " << rhs.name << ")" << std::endl;

					const bool ret = accumulateConstraint(*this, lhs, rhs);
					if (ret) {
						constraints++;
					}
				}

				/// Pairs evaluated
				int pairs;

				/// The number of constraints recognized: updated by specializations
				/// of accumulateConstraint()
				int constraints;

		};

		//--  Specializations of accumulateConstraint() Follow --//
		template<>
		struct ConstraintFromFeaturePair<Circle, Cylinder> {
			public:
				static bool accumulateConstraint(const Circle& lhs, const Cylinder& rhs, bool reverse) {
					std::cout << "Got a concentric constraint! (circle, cylinder) reverse = " << std::boolalpha << reverse << std::endl << std::endl;
					return true;
				}
		};
	} // end of namespace detail
} // end of namespace boundary_features

#endif // INCLUDED_BinaryConstraintVisitor_h_GUID_bebf5397_c20c_47c2_b4c1_5c1cd29e06fd
