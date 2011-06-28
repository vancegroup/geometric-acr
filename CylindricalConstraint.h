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
			static ConstraintPtr create(VectorPair const & points, VectorPair const & axes) {
				ConstraintPtr temp(new CylindricalConstraint(points, axes));
				return temp;
			}

			virtual ~CylindricalConstraint() {}
		protected:
			CylindricalConstraint(VectorPair const & points, VectorPair const & axes);
			void processNewPose();
		private:
			VectorPair _points;
			VectorPair _pointsXformed;
			VectorPair _axes;
			VectorPair _axesXformed;
	};

} // end of namespace boundary_features

#endif // INCLUDED_CylindricalConstraint_h_GUID_325b0222_9097_4835_92c9_c882c11ad4ef
