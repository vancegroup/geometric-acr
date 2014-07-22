/** @file
	@brief Header

	@date 2014

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef INCLUDED_RecognizeLimitedConstraints_h_GUID_bbb63350_2715_44fb_823e_e42ab8309c56
#define INCLUDED_RecognizeLimitedConstraints_h_GUID_bbb63350_2715_44fb_823e_e42ab8309c56

// Internal Includes
// - none

// Library/third-party includes
#include <boundary_features/RecognizeConstraints.h>

// Standard includes
#include <cstddef>

const char * getName(size_t i);
size_t getExperimentCondition();
size_t getNumSymmetric();
size_t getNumAsymmetric();

#endif // INCLUDED_RecognizeLimitedConstraints_h_GUID_bbb63350_2715_44fb_823e_e42ab8309c56
