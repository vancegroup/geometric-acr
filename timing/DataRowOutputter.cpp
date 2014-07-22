/**
	@file
	@brief Implementation

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

// Internal Includes
#include "DataRowOutputter.h"
#include "RecognizeLimitedConstraints.h"

// Library/third-party includes
// - none

// Standard includes
#include <bitset>
#include <sstream>

DataRowOutputter::DataRowOutputter(int iterations) : header_(), dataPrefix_() {

	std::bitset<BF_NUM_BITS> const recognizermask(getExperimentCondition());
	std::ostringstream headerstream;
	std::ostringstream datastream;

	// Output the label (to headerstream) and the content (to datastream)
	// in parallel structure, hence the unnecessary << between string literals and ","

	headerstream << "ExperimentCondition" << ",";
	datastream << getExperimentCondition() << ",";

	headerstream << "EnabledRecognizerMask" << ",";
	datastream << recognizermask << ",";

	{
		std::ostringstream recognizerstream;

		recognizerstream << "\"";

		for (size_t i = 0; i < BF_NUM_BITS; ++i) {
			if (recognizermask[i]) {
				recognizerstream << getName(i) << ".";
			}
		}
		recognizerstream << "\"";

		headerstream << "EnabledRecognizers" << ",";
		datastream << recognizerstream.str() << ",";
	}

	headerstream << "SymmetricRecognizers" << ",";
	datastream << getNumSymmetric() << ",";

	headerstream << "AsymmetricRecognizers" << ",";
	datastream << getNumAsymmetric() << ",";

	headerstream << "Iterations" << ",";
	datastream << iterations << ",";

	// These two vary with each trial.
	headerstream << "Trial,Elapsed";

	header_ = headerstream.str();
	dataPrefix_ = datastream.str();
}

void DataRowOutputter::outputHeaderRow(std::ostream & os) {
	os << header_ << std::endl;
}

void DataRowOutputter::outputDataRow(std::ostream & os, int trial, double elapsed) {
	os << dataPrefix_ << trial << "," << elapsed << std::endl;
}
