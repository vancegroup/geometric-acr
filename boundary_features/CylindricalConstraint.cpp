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
#include "CylindricalConstraint.h"

// Library/third-party includes
// - none

// Standard includes
#include <cmath>
#include <ostream>

//typedef Eigen::ParametrizedLine<double, 3> Line3d;
namespace boundary_features {

	CylindricalConstraint::CylindricalConstraint(GeometricConstraint::VectorPair const & points, GeometricConstraint::VectorPair const & axes, std::pair<double, double> const& radii)
		: _points(points)
		, _axes(axes)
		, _radii(radii)
		, _clearance(std::abs(_radii.first - _radii.second)) {
		processNewPose();
	}

	void CylindricalConstraint::processNewPose() {
		/* wikipedia:
		Because the magnitude of the cross product goes by the sine of the angle between its arguments, the cross product can be thought of as a measure of "perpendicularness" in the same way that the dot product is a measure of "parallelness". Given two unit vectors, their cross product has a magnitude of 1 if the two are perpendicular and a magnitude of zero if the two are parallel. The opposite is true for the dot product of two unit vectors.
		*/

		//std::pair<Line3d> lines( Line3d(_points.first, _axes.first), Line3d(_points.second, _axes.second));
		/// @todo
		_axesXformed = VectorPair(_pose().first.linear() * _axes.first,
		                          _pose().second.linear() * _axes.second);

		_pointsXformed = VectorPair(_pose().first * _points.first,
		                            _pose().second * _points.second);

		const Eigen::Vector3d rotationAxis = _axesXformed.first.cross(_axesXformed.second);
		const double crossNorm = rotationAxis.norm();
		const double d = std::abs((rotationAxis / crossNorm).dot(_pointsXformed.first - _pointsXformed.second));
		const double theta = std::asin(crossNorm);
		const double dDimensionless = d / _clearance;

		/// see pg 76 of Faas thesis
		setAlignment(0.5 * std::exp(-theta) + 0.5 * std::exp(-dDimensionless * 10.0));
	}

	void CylindricalConstraint::toText(std::ostream & os) const {
		os << "Cylindrical Constraint:"
		   << "Axis 1:" << std::endl
		   << _axes.first.transpose() << std::endl
		   << "Axis 2:" << std::endl
		   << _axes.second.transpose() << std::endl
		   << "Point 1:" << std::endl
		   << _points.first.transpose() << std::endl
		   << "Point 2:" << std::endl
		   << _points.second.transpose() << std::endl;
	}

	bool CylindricalConstraint::operator==(GeometricConstraint const& rhs) {
		CylindricalConstraint const * other = dynamic_cast<CylindricalConstraint const *>(&rhs);
		if (!other) {
			return false;
		}

		return _points == other->_points && _axes == other->_axes;
	}

} // end of namespace boundary_features
