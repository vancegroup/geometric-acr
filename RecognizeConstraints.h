/** @file RecognizeConstraints.h
	@brief Header for main constraint recognition function

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
	/** @brief The main constraint recognition function, returning constraints
		recognized based on all pairings between features in the given feature
		sets.

		To indicate that a feature pair should be recognized as leading to a constraint,
		create a template specialization of detail::ConstraintFromFeaturePair in a new header
		in detail/RecognizedPairs (see CircleCylinder.h for an example), and then include
		the new pair's header in RecognizeConstraints.cpp.
	*/
	struct RecognizedConstraints {
		int pairsChecked;
		int constraintsRecognized;
	};
	RecognizedConstraints recognizeConstraints(FeatureSet const & a, FeatureSet const& b);
} // end of namespace boundary_features

#endif // INCLUDED_RecognizeConstraints_h_GUID_da56693d_7825_4cfb_9719_7cb1df90d101
