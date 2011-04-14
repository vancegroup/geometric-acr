/** @file BoundaryFeatures.h
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
#ifndef INCLUDED_BoundaryFeatures_h_GUID_69687494_6822_4056_954a_9a94df3a2f0d
#define INCLUDED_BoundaryFeatures_h_GUID_69687494_6822_4056_954a_9a94df3a2f0d

// Internal Includes
#include "Circle.h"
#include "Cylinder.h"
#include "Plane.h"

// Library/third-party includes
#include <boost/variant/variant.hpp>

// Standard includes
#include <set>

namespace boundary_features {
	typedef boost::variant<Circle, Cylinder, Plane> BoundaryFeature;
	typedef std::set<BoundaryFeature> FeatureSet;
} // end of namespace boundary_features

#endif // INCLUDED_BoundaryFeatures_h_GUID_69687494_6822_4056_954a_9a94df3a2f0d
