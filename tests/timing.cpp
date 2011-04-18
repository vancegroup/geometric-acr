/**
	@file BinaryConstraintVisitor.cpp
	@brief

	@date 2011

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

// Internal Includes
#include <boundary_features/RecognizeConstraints.h>
#include <boundary_features/BoundaryFeatures.h>

// Library/third-party includes
#include <boost/timer.hpp>

// Standard includes
#include <iostream>
#include <cstdlib>

using namespace boundary_features;

inline bool flipCoin() {
	return std::rand() % 2;
}

double timeRecognition(FeatureSet const& a, FeatureSet const& b, int iterations) {
	boost::timer t;
	for (int i = 0; i < iterations; ++i) {
		int constraints = recognizeConstraints(a, b);
	}
	return t.elapsed();
}

int main() {
	Circle circle;
	Cylinder cylinder;
	Plane plane;

	FeatureSet a;
	if (flipCoin()) {	
		a.insert(circle);
	}
	if (flipCoin()) {	
		a.insert(cylinder);
	}
	if (flipCoin()) {	
		a.insert(plane);
	}

	FeatureSet b;
	if (flipCoin()) {	
		b.insert(circle);
	}
	if (flipCoin()) {	
		b.insert(cylinder);
	}
	if (flipCoin()) {	
		b.insert(plane);
	}
	
	const double GOAL_TIME = 3;
	int iterations = 100;
	double perOp;
	for (int trial = 0; trial < 5; ++trial) {
		std::cout << "Trying " << iterations << " iterations" << std::endl;
		double elapsed = timeRecognition(a, b, iterations);
		perOp = (elapsed / iterations);
		iterations = GOAL_TIME / perOp;
	}
	std::cout << "Time per operation: " << perOp << std::endl;
	std::cout << "Operations per second: " << 1.0 / perOp << std::endl;

	return 0;
}
