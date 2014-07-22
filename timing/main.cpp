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
#include "RecognizeLimitedConstraints.h"
#include "DataRowOutputter.h"
#include <boundary_features/BoundaryFeatures.h>

// Library/third-party includes
#include <boost/timer.hpp>

// Standard includes
#include <iostream>

using namespace boundary_features;

// Approximately enough to last 3 seconds.
const int ITERATIONS = 3000000;

const int TRIALS = 3;

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
	a.insert(circle);
	a.insert(cone);
	a.insert(cylinder);
	a.insert(plane);
	a.insert(sphere);

	FeatureSet b;
	b.insert(circle);
	b.insert(cone);
	b.insert(cylinder);
	b.insert(plane);
	b.insert(sphere);

	DataRowOutputter rowputter(ITERATIONS);
	rowputter.outputHeaderRow(std::cout);

	for (int trial = 0; trial < TRIALS; ++trial) {
		double elapsed = timeRecognition(a, b, ITERATIONS);
		rowputter.outputDataRow(std::cout, trial, elapsed);
	}
	return 0;
}
