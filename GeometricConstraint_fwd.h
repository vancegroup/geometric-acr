/** @file
	@brief Header

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef INCLUDED_GeometricConstraint_fwd_h_GUID_ecce9dac_6ce9_4076_a67a_63cea568c3c5
#define INCLUDED_GeometricConstraint_fwd_h_GUID_ecce9dac_6ce9_4076_a67a_63cea568c3c5

// Internal Includes
// - none

// Library/third-party includes
#include <boost/shared_ptr.hpp>

// Standard includes
#include <set>

namespace boundary_features {
	class GeometricConstraint;
	typedef boost::shared_ptr<GeometricConstraint> ConstraintPtr;
	typedef std::set<ConstraintPtr> ConstraintSet;
} // end of namespace boundary_features

#endif // INCLUDED_GeometricConstraint_fwd_h_GUID_ecce9dac_6ce9_4076_a67a_63cea568c3c5
