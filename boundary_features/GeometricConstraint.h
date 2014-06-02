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
#include "GeometricConstraint_fwd.h"

// Library/third-party includes
#include <Eigen/Eigen>

// Standard includes
#include <utility>
#include <iosfwd>

namespace boundary_features {

	class GeometricConstraint {
		public:
			EIGEN_MAKE_ALIGNED_OPERATOR_NEW
			typedef std::pair<Eigen::Affine3d, Eigen::Affine3d> PosePair;
			typedef std::pair<Eigen::Vector3d, Eigen::Vector3d> VectorPair;
			virtual ~GeometricConstraint() {};

			/// @brief Get alpha, the value in [0, 1] indicating how aligned we are with the constraint is.
			double getAlignment() const {
				return _alignment;
			}

			/// @brief Update the positions of the two objects
			void updatePoses(Eigen::Affine3d const& first, Eigen::Affine3d const& second);

			static ConstraintPtr null() {
				return ConstraintPtr();
			}

			virtual void toText(std::ostream & os) const = 0;

			virtual bool operator==(GeometricConstraint const&) {
				return false;
			}

		protected:
			/// Default constructor -protected to force subclassing.
			/// Inherited classes should also protect their constructors,
			/// and create a public static factory function "create" returning ConstraintPtr, too.
			GeometricConstraint();

			/// @brief Called when new poses are loaded - it should process them and call setAlpha()
			virtual void processNewPose() = 0;

			void setAlignment(double a);
			PosePair const& _pose() {
				return _poses;
			}

		private:
			double _alignment;
			PosePair _poses;
	};

	template<typename StreamType>
	StreamType & operator<<(StreamType & os, GeometricConstraint const& constraint) {
		constraint.toText(os);
		return os;
	}
} // end of namespace boundary_features

#endif // INCLUDED_GeometricConstraint_h_GUID_fbf5ef9e_87e5_4292_bbc0_4ed64702ac05
