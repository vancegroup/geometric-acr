/** @file CircleCylinder.h
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
#ifndef INCLUDED_CircleCylinder_h_GUID_a8d7dda7_e900_4ebf_9b31_d65c469cbeb5
#define INCLUDED_CircleCylinder_h_GUID_a8d7dda7_e900_4ebf_9b31_d65c469cbeb5

// Internal Includes
#include "../ConstraintFromFeaturePair_fwd.h"
#include "../../Circle.h"
#include "../../Cylinder.h"
#include "../../CylindricalConstraint.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace boundary_features {
	namespace detail {
		template<>
		struct ConstraintFromFeaturePair<Circle, Cylinder> {
			public:
				static ConstraintPtr accumulateConstraint(const Circle& lhs, const Cylinder& rhs, bool reverse) {
					if (reverse) {
						return CylindricalConstraint::create(std::make_pair(rhs.center, lhs.center), std::make_pair(rhs.normal, lhs.normal));
					}

					return CylindricalConstraint::create(std::make_pair(lhs.center, rhs.center), std::make_pair(lhs.normal, rhs.normal));
				}
		};

	} // end of namespace detail
} // end of namespace boundary_features

#endif // INCLUDED_CircleCylinder_h_GUID_a8d7dda7_e900_4ebf_9b31_d65c469cbeb5
