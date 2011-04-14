/** @file Plane.h
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
#ifndef INCLUDED_Plane_h_GUID_1b56a2dc_af86_4e85_b77e_c2f1fe0ed32c
#define INCLUDED_Plane_h_GUID_1b56a2dc_af86_4e85_b77e_c2f1fe0ed32c

// Internal Includes
// - none

// Library/third-party includes
#include <Eigen/Core>

// Standard includes
// - none

namespace boundary_features {
	struct Plane {
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW

		Plane() :
			name("Plane"),
			point(Eigen::Vector3d::Zero()),
			normal(Eigen::Vector3d::UnitX()) {}

		const char * name;

		Eigen::Vector3d point;
		Eigen::Vector3d normal;
	};
	
	inline bool operator<(Plane const& lhs, Plane const& rhs) {
		return lhs.point.squaredNorm() < rhs.point.squaredNorm() ? true :
			lhs.normal.squaredNorm() < rhs.normal.squaredNorm();
	}
} // end of namespace boundary_features

#endif // INCLUDED_Plane_h_GUID_1b56a2dc_af86_4e85_b77e_c2f1fe0ed32c
