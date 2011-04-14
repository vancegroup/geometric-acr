/** @file BinaryConstraintVisitor.h
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
#ifndef INCLUDED_BinaryConstraintVisitor_h_GUID_bebf5397_c20c_47c2_b4c1_5c1cd29e06fd
#define INCLUDED_BinaryConstraintVisitor_h_GUID_bebf5397_c20c_47c2_b4c1_5c1cd29e06fd

// Internal Includes
#include "BoundaryFeatures.h"

// Library/third-party includes
#include <boost/variant/static_visitor.hpp>

// Standard includes
#include <iostream>

namespace boundary_features {
	class BinaryConstraintVisitor;

	template<typename T, typename U>
	bool accumulateConstraint(BinaryConstraintVisitor & /*visitor*/, const T& lhs, const U& rhs) {
		std::cout << "No constraint!" << std::endl << std::endl;
		return false;
	}

	class BinaryConstraintVisitor : public boost::static_visitor<> {
		public:
			BinaryConstraintVisitor() : constraints(0) {}
			template<typename T, typename U>
			void operator()(const T& lhs, const U& rhs) {
				std::cout << "Left: name=" << lhs.name << std::endl;
				std::cout << "Right: name=" << rhs.name << std::endl;

				accumulateConstraint(*this, lhs, rhs);
			}

			int constraints;

	};

	template<>
	bool accumulateConstraint<Circle, Cylinder>(BinaryConstraintVisitor & visitor, const Circle& lhs, const Cylinder& rhs) {
		std::cout << "Got a concentric constraint! (circle, cylinder)" << std::endl << std::endl;
		visitor.constraints++;
		return true;
	}


	template<>
	bool accumulateConstraint<Cylinder, Circle>(BinaryConstraintVisitor & visitor, const Cylinder& lhs, const Circle& rhs) {
		std::cout << "Got a reverse-order concentric constraint! (cylinder, circle)" << std::endl << std::endl;
		visitor.constraints++;
		return true;
	}

} // end of namespace boundary_features

#endif // INCLUDED_BinaryConstraintVisitor_h_GUID_bebf5397_c20c_47c2_b4c1_5c1cd29e06fd
