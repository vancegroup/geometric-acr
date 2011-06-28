/**
	@file
	@brief Implementation

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

// Internal Includes
#include "GeometricConstraint.h"

// Library/third-party includes
// - none

// Standard includes
#include <stdexcept>

#define CONSTRAINT_STRICT_CHECKING

namespace boundary_features {

	static inline bool operator==(GeometricConstraint::PosePair const& a, GeometricConstraint::PosePair const& b) {
		return a.first.matrix() == b.first.matrix() && a.second.matrix() == b.second.matrix();
	}

	GeometricConstraint::GeometricConstraint() {

	}

	void GeometricConstraint::updatePoses(Eigen::Transform3d const& first, Eigen::Transform3d const& second) {
		PosePair newPoses(first, second);
		if (newPoses == _poses) {
			// this is actually not a change
		} else {
			_poses = newPoses;
			processNewPose();
		}
	}

	void GeometricConstraint::setAlpha(double a) {
#ifdef CONSTRAINT_STRICT_CHECKING
		if (a < 0.0 || a > 1.0) {
			throw std::out_of_range("alpha value computed by geometric constraint must be in [0, 1]!");
		}
#endif
		_alpha = a;
	}

} // end of namespace boundary_features
