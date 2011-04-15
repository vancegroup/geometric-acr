/** @file IsRecognized.h
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
#ifndef INCLUDED_IsRecognized_h_GUID_707bbb04_d182_4fef_969e_6acf063d6353
#define INCLUDED_IsRecognized_h_GUID_707bbb04_d182_4fef_969e_6acf063d6353

// Internal Includes
#include "ConstraintFromFeaturePair.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace boundary_features {
	namespace detail {

		template<typename T, typename U, typename Enable = void>
		struct IsRecognized {
			typedef void type;
		};

		template<typename T, typename U>
		struct IsRecognized<T, U, typename ConstraintFromFeaturePair<T, U>::unrecognized_tag> {};

		template<typename T, typename U, typename Enable = void>
		struct NotRecognized {};

		template<typename T, typename U>
		struct NotRecognized<T, U, typename ConstraintFromFeaturePair<T, U>::unrecognized_tag> {
			typedef void type;
		};

	} // end of namespace detail
} // end of namespace boundary_features

#endif // INCLUDED_IsRecognized_h_GUID_707bbb04_d182_4fef_969e_6acf063d6353
