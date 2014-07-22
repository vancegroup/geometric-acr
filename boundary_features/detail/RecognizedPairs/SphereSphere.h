/** @file SphereSphere.h
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
#ifndef INCLUDED_SphereSphere_h_GUID_202e767d_0db1_4ede_a84b_aa27b98d7f6a
#define INCLUDED_SphereSphere_h_GUID_202e767d_0db1_4ede_a84b_aa27b98d7f6a

// Internal Includes
#include "../ConstraintFromFeaturePair_fwd.h"
#include "../../Sphere.h"
#include "../../GeometricConstraint.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace boundary_features {
	namespace detail {

		/// Spherical constraint
		template<>
		struct ConstraintFromFeaturePair<Sphere, Sphere> {
			public:
				static ConstraintPtr accumulateConstraint(const Sphere& lhs, const Sphere& rhs, bool reverse) {
					return NotYetImplementedConstraint::create();
				}
		};

	} // end of namespace detail
} // end of namespace boundary_features

#endif // INCLUDED_SphereSphere_h_GUID_202e767d_0db1_4ede_a84b_aa27b98d7f6a
