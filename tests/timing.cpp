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
	//return std::rand() % 2;
	return true;
}

double timeRecognition(FeatureSet const& a, FeatureSet const& b, int iterations) {
	boost::timer t;
	for (int i = 0; i < iterations; ++i) {
		recognizeConstraints(a, b);
	}
	return t.elapsed();
}

int main() {
	Circle circle;
	Cone cone;
	Cylinder cylinder;
	Plane plane;
	Sphere sphere;

	FeatureSet a;
	if (flipCoin()) {
		a.insert(circle);
	}
	if (flipCoin()) {
		a.insert(cone);
	}
	if (flipCoin()) {
		a.insert(cylinder);
	}
	if (flipCoin()) {
		a.insert(plane);
	}
	if (flipCoin()) {
		a.insert(sphere);
	}

	FeatureSet b;
	if (flipCoin()) {
		b.insert(circle);
	}
	if (flipCoin()) {
		b.insert(cone);
	}
	if (flipCoin()) {
		b.insert(cylinder);
	}
	if (flipCoin()) {
		b.insert(plane);
	}
	if (flipCoin()) {
		b.insert(sphere);
	}

	RecognizedConstraints c = recognizeConstraints(a, b);
	std::cout << "Checking " << c.pairsChecked << " pairs to find " << c.constraintsRecognized << " constraints" << std::endl;
	double pairs = c.pairsChecked;

	const double GOAL_TIME = 3;
	int iterations = 1000000;
	double perOp;
	for (int trial = 0; trial < 5; ++trial) {
		std::cout << std::endl << "Trying " << iterations << " iterations" << std::endl;
		double elapsed = timeRecognition(a, b, iterations);
		perOp = elapsed / static_cast<double>(iterations);
		std::cout << "elapsed: " << elapsed << std::endl;
		iterations = GOAL_TIME / perOp;
	}
	std::cout << std::endl;
	std::cout << "Time per pair checked: " << (perOp / pairs) << std::endl;
	std::cout << "Pairs checked per second: " << 1.0 / (perOp / pairs) << std::endl;
	std::cout << "Pairs checked per millisecond: " << 0.001 / (perOp / pairs) << std::endl;
	return 0;
}
