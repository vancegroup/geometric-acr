/** @file Cylinder.h
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
#ifndef INCLUDED_Cylinder_h_GUID_bd66677a_f108_4556_9b9e_d8ace3b8b6ad
#define INCLUDED_Cylinder_h_GUID_bd66677a_f108_4556_9b9e_d8ace3b8b6ad

// Internal Includes
// - none

// Library/third-party includes
#include <Eigen/Core>

// Standard includes
#include <string>

namespace boundary_features {
	struct Cylinder {
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW

		Cylinder() :
			name("Cylinder"),
			center(Eigen::Vector3d::Zero()),
			normal(Eigen::Vector3d::UnitX()),
			radius(0.0) {}

		std::string name;

		Eigen::Vector3d center;
		Eigen::Vector3d normal;
		double radius;
	};

	inline bool operator<(Cylinder const& lhs, Cylinder const& rhs) {
		return lhs.radius < rhs.radius ? true :
		       lhs.center.squaredNorm() < rhs.center.squaredNorm() ? true :
		       lhs.normal.squaredNorm() < rhs.normal.squaredNorm();
	}
	/// @todo check for equivalence not just exact equality
	inline bool operator==(Cylinder const& lhs, Cylinder const& rhs) {
		return lhs.radius == rhs.radius &&
		       lhs.center == rhs.center &&
		       lhs.normal == rhs.normal;
	}
} // end of namespace boundary_features

#endif // INCLUDED_Cylinder_h_GUID_bd66677a_f108_4556_9b9e_d8ace3b8b6ad
