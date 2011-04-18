/** @file Sphere.h
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
#ifndef INCLUDED_Sphere_h_GUID_b114af88_743e_41a9_8a10_7b3b92e6ee85
#define INCLUDED_Sphere_h_GUID_b114af88_743e_41a9_8a10_7b3b92e6ee85

// Internal Includes
// - none

// Library/third-party includes
#include <Eigen/Core>

// Standard includes
#include <string>

namespace boundary_features {
	struct Sphere {
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW

		Sphere() :
			name("Sphere"),
			center(Eigen::Vector3d::Zero()),
			radius(0.0) {}

		std::string name;
		Eigen::Vector3d center;
		double radius;
	};

	inline bool operator<(Sphere const& lhs, Sphere const& rhs) {
		return lhs.radius < rhs.radius ? true :
		       lhs.center.squaredNorm() < rhs.center.squaredNorm();
	}
} // end of namespace boundary_features

#endif // INCLUDED_Sphere_h_GUID_b114af88_743e_41a9_8a10_7b3b92e6ee85
