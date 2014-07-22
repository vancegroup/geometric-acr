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

#ifndef INCLUDED_DataRowOutputter_h_GUID_5ed8ebd2_18e3_438c_ad6f_0795b66db0c1
#define INCLUDED_DataRowOutputter_h_GUID_5ed8ebd2_18e3_438c_ad6f_0795b66db0c1

// Internal Includes
// - none

// Library/third-party includes
// - none

// Standard includes
#include <iosfwd>
#include <string>

/// @brief Class to keep the csv data output stuff out of the main timing code.
class DataRowOutputter {
	public:
		DataRowOutputter(int iterations);
		void outputHeaderRow(std::ostream & os);
		void outputDataRow(std::ostream & os, int trial, double elapsed);
	private:
		std::string header_;
		std::string dataPrefix_;
};

#endif // INCLUDED_DataRowOutputter_h_GUID_5ed8ebd2_18e3_438c_ad6f_0795b66db0c1
