/**
 * @file AllTests.cpp
 * @author Francisco Magdaleno Garrido <francisco.magdalenog@gmail.com>
 * @brief Punto de entrada del framework
 **/

#include "gtest/gtest.h"

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/BriefTestProgressListener.h>

#include "test.h"

int MAIN {
	RUN_TESTS()
}
