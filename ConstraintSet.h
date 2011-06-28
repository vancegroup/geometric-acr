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
#ifndef INCLUDED_ConstraintSet_h_GUID_d32a622b_553a_4570_bcaf_91f71a7378d6
#define INCLUDED_ConstraintSet_h_GUID_d32a622b_553a_4570_bcaf_91f71a7378d6

// Internal Includes
#include "GeometricConstraint_fwd.h"

// Library/third-party includes
// - none

// Standard includes
#include <set>

namespace boundary_features {
	class ConstraintSet {
		public:
			typedef std::set<ConstraintPtr> container;

			typedef container::iterator iterator;
			typedef container::const_iterator const_iterator;
			typedef container::size_type size_type;
		private:
			container _set;
		public:
			ConstraintSet() {}


			const_iterator begin() const {
				return _set.begin();
			}
			const_iterator end() const {
				return _set.end();
			}
			bool find(ConstraintPtr const& constraint) const;

			bool containsSubset(ConstraintSet const& other) const;

			iterator insert(ConstraintPtr const& constraint);
			void erase(ConstraintPtr const& constraint);
			bool extend(ConstraintSet const& other);

			container::size_type size() const {
				return _set.size();
			}
			bool empty() const {
				return _set.empty();
			}

	};

} // end of namespace boundary_features

#endif // INCLUDED_ConstraintSet_h_GUID_d32a622b_553a_4570_bcaf_91f71a7378d6
