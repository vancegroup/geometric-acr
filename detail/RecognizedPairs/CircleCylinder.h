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

// Library/third-party includes
// - none

// Standard includes
#include <iostream>

namespace boundary_features {
	namespace detail {
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

#endif // INCLUDED_CircleCylinder_h_GUID_a8d7dda7_e900_4ebf_9b31_d65c469cbeb5
