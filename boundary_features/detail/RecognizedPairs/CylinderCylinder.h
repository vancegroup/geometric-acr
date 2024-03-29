/** @file CylinderCylinder.h
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
#ifndef INCLUDED_CylinderCylinder_h_GUID_8b7769f7_f9df_45fe_a37e_47b18b695af3
#define INCLUDED_CylinderCylinder_h_GUID_8b7769f7_f9df_45fe_a37e_47b18b695af3

// Internal Includes
#include "../ConstraintFromFeaturePair_fwd.h"
#include "../../Cylinder.h"
#include "../../CylindricalConstraint.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace boundary_features {
	namespace detail {

		/// Cylindrical constraint
		template<>
		struct ConstraintFromFeaturePair<Cylinder, Cylinder> {
			public:
				static ConstraintPtr accumulateConstraint(const Cylinder& lhs, const Cylinder& rhs, bool reverse) {
					if (reverse) {
						return ConstraintFromFeaturePair::accumulateConstraint(rhs, lhs, false);
					}

					return CylindricalConstraint::create(std::make_pair(lhs.center, rhs.center), std::make_pair(lhs.normal, rhs.normal), std::make_pair(lhs.radius, rhs.radius));
				}
		};

	} // end of namespace detail
} // end of namespace boundary_features

#endif // INCLUDED_CylinderCylinder_h_GUID_8b7769f7_f9df_45fe_a37e_47b18b695af3
