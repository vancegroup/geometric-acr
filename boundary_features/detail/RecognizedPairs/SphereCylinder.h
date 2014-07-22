/** @file SphereCylinder.h
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
#ifndef INCLUDED_SphereCylinder_h_GUID_9350cd0d_d4dd_4ecf_9b86_3c1f0f5f3de9
#define INCLUDED_SphereCylinder_h_GUID_9350cd0d_d4dd_4ecf_9b86_3c1f0f5f3de9

// Internal Includes
#include "../ConstraintFromFeaturePair_fwd.h"
#include "../../Sphere.h"
#include "../../Cylinder.h"
#include "../../GeometricConstraint.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace boundary_features {
	namespace detail {

		/// Linear annular fit
		template<>
		struct ConstraintFromFeaturePair<Sphere, Cylinder> {
			public:
				static ConstraintPtr accumulateConstraint(const Sphere& lhs, const Cylinder& rhs, bool reverse) {
					return NotYetImplementedConstraint::create();
				}
		};

	} // end of namespace detail
} // end of namespace boundary_features

#endif // INCLUDED_SphereCylinder_h_GUID_9350cd0d_d4dd_4ecf_9b86_3c1f0f5f3de9
