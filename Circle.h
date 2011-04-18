/** @file Circle.h
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
#ifndef INCLUDED_Circle_h_GUID_d0a7de7d_a284_4ab9_bb8a_c7672a4618ab
#define INCLUDED_Circle_h_GUID_d0a7de7d_a284_4ab9_bb8a_c7672a4618ab

// Internal Includes
// - none

// Library/third-party includes
#include <Eigen/Core>

// Standard includes
#include <string>

namespace boundary_features {
	struct Circle {
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW

		Circle() :
			name("Circle"),
			center(Eigen::Vector3d::Zero()),
			normal(Eigen::Vector3d::UnitX()),
			radius(0.0) {}

		std::string name;
		Eigen::Vector3d center;
		Eigen::Vector3d normal;
		double radius;
	};

	inline bool operator<(Circle const& lhs, Circle const& rhs) {
		return lhs.radius < rhs.radius ? true :
		       lhs.center.squaredNorm() < rhs.center.squaredNorm() ? true :
		       lhs.normal.squaredNorm() < rhs.normal.squaredNorm();
	}
} // end of namespace boundary_features

#endif // INCLUDED_Circle_h_GUID_d0a7de7d_a284_4ab9_bb8a_c7672a4618ab
