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
			CylindricalConstraint(VectorPair points, VectorPair axes);
			virtual ~CylindricalConstraint() {}
		protected:
			void processNewPose();
		private:
			VectorPair _points;
			VectorPair _pointsXformed;
			VectorPair _axes;
			VectorPair _axesXformed;
	};

} // end of namespace boundary_features

#endif // INCLUDED_CylindricalConstraint_h_GUID_325b0222_9097_4835_92c9_c882c11ad4ef
