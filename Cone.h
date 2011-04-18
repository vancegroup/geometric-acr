/** @file Cone.h
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
#ifndef INCLUDED_Cone_h_GUID_97893b75_0ba2_4894_b664_d3286f112276
#define INCLUDED_Cone_h_GUID_97893b75_0ba2_4894_b664_d3286f112276

// Internal Includes
// - none

// Library/third-party includes
#include <Eigen/Core>

// Standard includes
#include <string>

namespace boundary_features {
	struct Cone {
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW

		Cone() :
			name("Cone"),
			center(Eigen::Vector3d::Zero()),
			axis(Eigen::Vector3d::UnitX()),
			ref(Eigen::Vector3d::UnitX()),
			halfangle(0.0),
			radius(0.0) {}

		std::string name;
		Eigen::Vector3d center;
		Eigen::Vector3d axis;
		Eigen::Vector3d ref;
		double halfangle;
		double radius;
	};

	inline bool operator<(Cone const& lhs, Cone const& rhs) {
		return lhs.radius < rhs.radius ? true :
		       lhs.halfangle < rhs.halfangle ? true :
		       lhs.center.squaredNorm() < rhs.center.squaredNorm() ? true :
		       lhs.axis.squaredNorm() < rhs.axis.squaredNorm() ? true :
		       lhs.ref.squaredNorm() < rhs.ref.squaredNorm();
	}
} // end of namespace boundary_features

#endif // INCLUDED_Cone_h_GUID_97893b75_0ba2_4894_b664_d3286f112276
