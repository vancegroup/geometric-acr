/** @file accumulateConstraint.h
	@brief

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef INCLUDED_accumulateConstraint_h_GUID_40ddffe5_4aa5_4f8c_8936_d5e34db5138c
#define INCLUDED_accumulateConstraint_h_GUID_40ddffe5_4aa5_4f8c_8936_d5e34db5138c

// Internal Includes
#include "IsRecognized.h"

// Library/third-party includes
// - none

// Standard includes
// - none


namespace boundary_features {
	namespace detail {

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
		ConstraintPtr accumulateConstraint(const T& /*lhs*/,
		                                   const U& /*rhs*/,
		                                   typename NotRecognized<T, U>::type* = 0,
		                                   typename NotRecognized<U, T>::type* = 0) {
			return ConstraintPtr();
		}

		template<typename T, typename U>
		ConstraintPtr accumulateConstraint(const T& lhs,
		                                   const U& rhs,
		                                   typename IsRecognized<T, U>::type* = 0,
		                                   typename NotRecognized<U, T>::type* = 0) {
			return ConstraintFromFeaturePair<T, U>::accumulateConstraint(lhs, rhs, false);
		}
		template<typename T, typename U>
		ConstraintPtr accumulateConstraint(const T& lhs,
		                                   const U& rhs,
		                                   typename NotRecognized<T, U>::type* = 0,
		                                   typename IsRecognized<U, T>::type* = 0) {
			return ConstraintFromFeaturePair<U, T>::accumulateConstraint(rhs, lhs, true);
		}

		template<typename T>
		ConstraintPtr accumulateConstraint(const T& lhs,
		                                   const T& rhs,
		                                   typename IsRecognized<T, T>::type* = 0) {
			return ConstraintFromFeaturePair<T, T>::accumulateConstraint(lhs, rhs, false);
		}

	} // end of namespace detail
} // end of namespace boundary_features


#endif // INCLUDED_accumulateConstraint_h_GUID_40ddffe5_4aa5_4f8c_8936_d5e34db5138c
