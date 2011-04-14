/** @file Constraint.h
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
#ifndef INCLUDED_Constraint_h_GUID_bd608238_9ecb_4b66_8b61_eceeec6d9b2b
#define INCLUDED_Constraint_h_GUID_bd608238_9ecb_4b66_8b61_eceeec6d9b2b

// Internal Includes
// - none

// Library/third-party includes
// - none

// Standard includes
// - none

namespace boundary_features {
	class Constraint {
		public:
			virtual ~Constraint() = 0;
	};
	
	inline Constraint::~Constraint() {}

} // end of namespace boundary_features

#endif // INCLUDED_Constraint_h_GUID_bd608238_9ecb_4b66_8b61_eceeec6d9b2b
