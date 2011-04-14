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
	class Constraint;
	class BinaryConstraintVisitor;
	template<typename T, typename U>
	Constraint * recognizeConstraint(BinaryConstraintVisitor & /*visitor*/, const T& lhs, const U& rhs) {
		std::cout << "No constraint!" << std::endl << std::endl;
		return NULL;
	}
	class BinaryConstraintVisitor : public boost::static_visitor<Constraint *> {
		public:
			BinaryConstraintVisitor() : constraints(0) {}
			template<typename T, typename U>
			Constraint * operator()(const T& lhs, const U& rhs) {
				std::cout << "Left: name=" << lhs.name << std::endl;
				std::cout << "Right: name=" << rhs.name << std::endl;

				return recognizeConstraint(*this, lhs, rhs);
			}

			int constraints;

	};

	template<>
	Constraint * recognizeConstraint<Circle, Cylinder>(BinaryConstraintVisitor & visitor, const Circle& lhs, const Cylinder& rhs) {
		std::cout << "Got a concentric constraint! (circle, cylinder)" << std::endl << std::endl;
		visitor.constraints++;
		return NULL;
	}

} // end of namespace boundary_features

#endif // INCLUDED_BinaryConstraintVisitor_h_GUID_bebf5397_c20c_47c2_b4c1_5c1cd29e06fd
