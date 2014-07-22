/** @file ConeCone.h
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
#ifndef INCLUDED_ConeCone_h_GUID_4403d90b_8586_478d_bda9_e0d361fac4b8
#define INCLUDED_ConeCone_h_GUID_4403d90b_8586_478d_bda9_e0d361fac4b8

// Internal Includes
#include "../ConstraintFromFeaturePair_fwd.h"
#include "../../Cone.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace boundary_features {
	namespace detail {

		/// Unidirectional cylindrical constraint
		template<>
		struct ConstraintFromFeaturePair<Cone, Cone> {
			public:
				static ConstraintPtr accumulateConstraint(const Cone& lhs, const Cone& rhs, bool reverse) {
					return NotYetImplementedConstraint::create();
				}
		};

	} // end of namespace detail
} // end of namespace boundary_features


#endif // INCLUDED_ConeCone_h_GUID_4403d90b_8586_478d_bda9_e0d361fac4b8
