/** @file BoundaryFeatures_fwd.h
	@brief Forward declarations of all boundary features types. To work
	with or store them, include BoundaryFeatures.

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef INCLUDED_BoundaryFeatures_fwd_h_GUID_58d1b743_13fb_4b5c_a006_5c76181e2b55
#define INCLUDED_BoundaryFeatures_fwd_h_GUID_58d1b743_13fb_4b5c_a006_5c76181e2b55

// Internal Includes
// - none

// Library/third-party includes
#include <boost/variant/variant_fwd.hpp>
#include <Eigen/Core>

// Standard includes
#include <set>

namespace boundary_features {
	struct Circle;
	struct Cone;
	struct Cylinder;
	struct Plane;
	struct Sphere;

	/// Variant type that can hold any boundary feature. Generally no need
	/// to manipulate this directly.
	typedef boost::variant <
	Circle
	,
	Cone
	,
	Cylinder
	,
	Plane
	,
	Sphere
	> BoundaryFeature;

	/// Set containing unique boundary features.
	typedef std::set<BoundaryFeature, std::less<BoundaryFeature>, Eigen::aligned_allocator<BoundaryFeature> > FeatureSet;
} // end of namespace boundary_features

#endif // INCLUDED_BoundaryFeatures_fwd_h_GUID_58d1b743_13fb_4b5c_a006_5c76181e2b55
