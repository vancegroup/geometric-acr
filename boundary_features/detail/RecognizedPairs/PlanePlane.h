/** @file PlanePlane.h
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
#ifndef INCLUDED_PlanePlane_h_GUID_c1a7078d_9092_426c_b9ce_e1d8bd00a258
#define INCLUDED_PlanePlane_h_GUID_c1a7078d_9092_426c_b9ce_e1d8bd00a258

// Internal Includes
#include "../ConstraintFromFeaturePair_fwd.h"
#include "../../Plane.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace boundary_features {
	namespace detail {

		/// Planar fit
		template<>
		struct ConstraintFromFeaturePair<Plane, Plane> {
			public:
				static ConstraintPtr accumulateConstraint(const Plane& lhs, const Plane& rhs, bool reverse) {
					return NotYetImplementedConstraint::create();
				}
		};

	} // end of namespace detail
} // end of namespace boundary_features

#endif // INCLUDED_PlanePlane_h_GUID_c1a7078d_9092_426c_b9ce_e1d8bd00a258

