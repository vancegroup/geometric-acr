/** @file RecognizeConstraints.h
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
#ifndef INCLUDED_RecognizeConstraints_h_GUID_da56693d_7825_4cfb_9719_7cb1df90d101
#define INCLUDED_RecognizeConstraints_h_GUID_da56693d_7825_4cfb_9719_7cb1df90d101

// Internal Includes
#include "BoundaryFeatures_fwd.h"

// Library/third-party includes
// - none

// Standard includes
// - none


namespace boundary_features {
	int recognizeConstraints(FeatureSet const & a, FeatureSet const& b);
} // end of namespace boundary_features

#endif // INCLUDED_RecognizeConstraints_h_GUID_da56693d_7825_4cfb_9719_7cb1df90d101
