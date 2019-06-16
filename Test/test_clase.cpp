/**
*@file Test/test_clase.cpp
*@author Francisco Magdaleno <francisco.magdalenog@gmail.com>
*@brief Tests sobre los metodos de la calculadora
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
#include "test_clase.test"

/**
 * @namespace Tester
 * @brief Este namespace es el encargado de la definición de los test suites, los test y la propia llamada a estos últimos 
 */
namespace Tester
{
	/**
	 * @cond 
	 */
	TEST_SUITE_BEGIN(ctest_calculadora)	 
	TEST_METHOD(ctest_calculadora,test_cal_run_tests)
	TEST_METHOD(ctest_calculadora,test_suma)
	TEST_SUITE_END()
	/**
	 * @endcond 
	 */
}

