/**
	@author
	Ryan Pavlik ( <rpavlik@iastate.edu> http://academic.cleardefinition.com/ ),
	Iowa State University
	Virtual Reality Applications Center and
	Human-Computer Interaction Graduate Program
*/

#define BOOST_TEST_MODULE Boundary features tests

// Internal Includes
#include <boundary_features/BoundaryFeatures.h>

// Library/third-party includes
#include <BoostTestTargetConfig.h>

using namespace boost::unit_test;
/*
BOOST_AUTO_TEST_CASE(Construction) {
	BOOST_CHECK_NO_THROW( Simulation firstone );
}

BOOST_AUTO_TEST_CASE(ThreadStartAndStop) {
	Simulation s;
	s.startMaxSpeedLoop();
	s.sendStopSignal();
	s.waitForStop();
}

BOOST_AUTO_TEST_CASE(SimMaxFrames) {
	Simulation s;
	s.setMaxFrames(2000);
	s.startMaxSpeedLoop();
	s.waitForStop();
}

BOOST_AUTO_TEST_CASE(SimSchedulerMaxFrames) {
	Simulation s;
	s.setMaxFrames(2000);
	s.startInSchedulerThread();
	s.waitForStop();
}

BOOST_AUTO_TEST_CASE(ThreadSingleStart) {
	Simulation s;
	/// @todo minor race condition: betting that 2000 frames takes longer than checking for the exception
	s.setMaxFrames(2000);
	s.startMaxSpeedLoop();
	BOOST_CHECK_THROW(s.startMaxSpeedLoop(), Simulation::AlreadyRunningException);
	s.waitForStop();
}

BOOST_AUTO_TEST_CASE(RunEmpty) {
	Simulation s;
	BOOST_CHECK_NO_THROW(s.simulationSinglePass());
}
*/
