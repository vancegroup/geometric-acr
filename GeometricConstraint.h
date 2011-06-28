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
#ifndef INCLUDED_GeometricConstraint_h_GUID_fbf5ef9e_87e5_4292_bbc0_4ed64702ac05
#define INCLUDED_GeometricConstraint_h_GUID_fbf5ef9e_87e5_4292_bbc0_4ed64702ac05

// Internal Includes
// - none

// Library/third-party includes
#include <core/SimTypes.h>
#include <boost/shared_ptr.hpp>

// Standard includes
#include <utility>

namespace boundary_features {

	class GeometricConstraint {
		public:
			typedef std::pair<Eigen::Transform3d, Eigen::Transform3d> PosePair;
			typedef std::pair<Eigen::Vector3d, Eigen::Vector3d> VectorPair;
			virtual ~GeometricConstraint() {};

			virtual bool isValid() const {
				return true;
			}

			/// @brief Get alpha, the value in [0, 1] indicating how engaged the constraint is.
			double getEngagement() const {
				return _alpha;
			}

			/// @brief Update the positions of the two objects
			void updatePoses(Eigen::Transform3d const& first, Eigen::Transform3d const& second);
		protected:
			GeometricConstraint();
			virtual void processNewPose() = 0;
			void setAlpha(double a);
			PosePair const& _pose() {
				return _poses;
			}

		private:
			double _alpha;
			PosePair _poses;
	};

	typedef boost::shared_ptr<GeometricConstraint> ConstraintPtr;

	class NullConstraint : public GeometricConstraint {
		public:
			virtual ~NullConstraint() {}

			virtual bool isValid() const {
				return false;
			}

			static ConstraintPtr create() {
				ConstraintPtr temp(new NullConstraint);
				return temp;
			}

		protected:
			NullConstraint() : GeometricConstraint() {}
			virtual void processNewPose() {
				/* no-op */
			}
	};
} // end of namespace boundary_features

#endif // INCLUDED_GeometricConstraint_h_GUID_fbf5ef9e_87e5_4292_bbc0_4ed64702ac05
