/**
	@file
	@brief Implementation

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

// Internal Includes
#include "ConstraintSet.h"
#include "GeometricConstraint.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace boundary_features {
	bool ConstraintSet::find(ConstraintPtr const& constraint) const {
		// no null constraints.
		if (!constraint) {
			return false;
		}

		iterator result = _set.find(constraint);
		if (result != end()) {
			return true;
		}

		for (iterator it = begin(); it != end(); ++it) {
			if (*(*it) == *constraint) {
				return true;
			}
		}

		return false;
	}

	bool ConstraintSet::containsSubset(ConstraintSet const& other) const {
		for (const_iterator it = other.begin(); it != other.end(); ++it) {
			if (!find(*it)) {
				return false;
			}
		}
		return true;
	}

	ConstraintSet::iterator ConstraintSet::insert(ConstraintPtr const& constraint) {
		// no adding null constraints.
		if (!constraint) {
			return end();
		}

		if (find(constraint)) {
			// no adding duplicate constraints.
			return end();
		}

		// OK, can insert now.
		return _set.insert(constraint).first;
	}

	void ConstraintSet::erase(ConstraintPtr const& constraint) {
		// no removing null constraints.
		if (!constraint) {
			return;
		}

		_set.erase(constraint);
	}

	bool ConstraintSet::extend(ConstraintSet const& other) {
		bool inserted = false;
		for (iterator it = other.begin(); it != other.end(); ++it) {
			insert(*it);
		}
	}


} // end of namespace boundary_features
