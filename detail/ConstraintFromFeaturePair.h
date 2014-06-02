/** @file ConstraintFromFeaturePair.h
	@brief ConstraintFromFeaturePair template default implementation, which
	signals that a particular feature pair is not recognized.

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

#pragma once
#ifndef INCLUDED_ConstraintFromFeaturePair_h_GUID_6b369dfa_09e2_4c1c_a51e_296d8739a2ba
#define INCLUDED_ConstraintFromFeaturePair_h_GUID_6b369dfa_09e2_4c1c_a51e_296d8739a2ba

// Internal Includes
// - none

// Library/third-party includes
// - none

// Standard includes
// - none

namespace boundary_features {
	namespace detail {

		struct UnrecognizedFeaturePair {
			typedef void unrecognized_tag;
		};

		template<typename T, typename U>
		struct ConstraintFromFeaturePair : UnrecognizedFeaturePair {};

	} // end of namespace detail
} // end of namespace boundary_features

#endif // INCLUDED_ConstraintFromFeaturePair_h_GUID_6b369dfa_09e2_4c1c_a51e_296d8739a2ba
