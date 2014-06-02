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
#ifndef INCLUDED_CylindricalConstraint_h_GUID_325b0222_9097_4835_92c9_c882c11ad4ef
#define INCLUDED_CylindricalConstraint_h_GUID_325b0222_9097_4835_92c9_c882c11ad4ef

// Internal Includes
#include "GeometricConstraint.h"

// Library/third-party includes
// - none

// Standard includes
// - none


namespace boundary_features {

	class CylindricalConstraint : public GeometricConstraint {
		public:
			EIGEN_MAKE_ALIGNED_OPERATOR_NEW
			static ConstraintPtr create(VectorPair const & points, VectorPair const & axes, std::pair<double, double> const& radii) {
				ConstraintPtr temp(new CylindricalConstraint(points, axes, radii));
				return temp;
			}

			virtual ~CylindricalConstraint() {}
			virtual void toText(std::ostream & os) const;
			virtual bool operator==(GeometricConstraint const& rhs);
		protected:
			CylindricalConstraint(VectorPair const & points, VectorPair const & axes, std::pair<double, double> const& radii);
			void processNewPose();
		private:
			VectorPair _points;
			VectorPair _pointsXformed;
			VectorPair _axes;
			VectorPair _axesXformed;
			std::pair<double, double> _radii;
			const double _clearance;
	};

} // end of namespace boundary_features

#endif // INCLUDED_CylindricalConstraint_h_GUID_325b0222_9097_4835_92c9_c882c11ad4ef
