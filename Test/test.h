/**
 * @file test.h
 * @author Francisco Magdaleno Garrido <francisco.magdalenog@gmail.com>
 * @brief Macros para sobrecargar los metodos de las diferentes plataformas. \n
 * <b> Macros [1/2] corresponden a GOOGLE TEST </b> \n
 * <b> Macros [2/2] corresponden a CPPUNIT </b>
 **/

#ifdef GOOGLE_TEST_ENABLED
/**
 * @def CHECK_EQ_INT
 * @param X valor esperado
 * @param Y valor actual
 * @brief Comprueba que los valores enteros X e Y son iguales.
 **/
#define CHECK_EQ_INT(X,Y) ASSERT_EQ(X,Y)
/**
 * @def CHECK_EQ_FLOAT
 * @param X valor esperado
 * @param Y valor actual
 * @brief Comprueba que dos valores flotantes son iguales.
 **/
#define CHECK_EQ_FLOAT(X,Y) ASSERT_FLOAT_EQ(X,Y)

/**
 * @def CHECK_NE
 * @param X valor esperado
 * @param Y valor actual
 * @brief Comprueba que los valores X e Y no son iguales.
 **/
#define CHECK_NE(X,Y) ASSERT_NE(X,Y)
/**
 * @def CHECK_LT
 * @param X valor esperado
 * @param Y valor actual
 * @brief Comprueba que el valor X es menor que el valor Y.
 **/
#define CHECK_LT(X,Y) ASSERT_LT(X,Y)
/**
 * @def CHECK_LE
 * @param X valor esperado
 * @param Y valor actual
 * @brief Comprueba que el valor X es menor o igual al valor Y.
 **/
#define CHECK_LE(X,Y) ASSERT_LE(X,Y)
/**
 * @def CHECK_GT
 * @param X valor esperado
 * @param Y valor actual
 * @brief Comprueba que el valor X es mayor al valor Y.
 **/
#define CHECK_GT(X,Y) ASSERT_GT(X,Y)
/**
 * @def CHECK_GE
 * @param X valor esperado
 * @param Y valor actual
 * @brief Comprueba que el valor X es mayor o igual al valor Y.
 **/
#define CHECK_GE(X,Y) ASSERT_GE(X,Y)
/**
 * @def CHECK_STREQ
 * @param X string esperado
 * @param Y string actual
 * @brief Comprueba que las cadenas X e Y son iguales.
 **/
#define CHECK_STREQ(X,Y) ASSERT_STREQ(X,Y)
/**
 * @def CHECK_STRNE
 * @param X string esperado
 * @param Y string actual
 * @brief Comprueba que las cadenas X e Y son diferentes.
 **/
#define CHECK_STRNE(X,Y) ASSERT_STRNE(X,Y)
/**
 * @def CHECK_BOOLEAN_TRUE
 * @param X variable booleana a comprobar
 * @brief Comprueba que el booleano o expresión X es verdadera.
 **/
#define CHECK_BOOLEAN_TRUE(X) ASSERT_TRUE(X)
/**
 * @def CHECK_BOOLEAN_FALSE
 * @param X variable booleana a comprobar
 * @brief Comprueba que el booleano o expresión X es falsa.
 **/
#define CHECK_BOOLEAN_FALSE(X) ASSERT_FALSE(X)
/**
 * @def CHECK_NULL_POINTER
 * @param X puntero con valor nulo
 * @brief Comprueba que el puntero X es nulo.
 **/
#define CHECK_NULL_POINTER(X) ASSERT_TRUE(X == nullptr)
/**
 * @def INHERITANCE
 * @brief Define la herencia de la clase.
 **/
#define INHERITANCE ::testing::Test 
/**
 * @def TEST_SUITE_BEGIN
 * @param X nombre del test suite
 * @brief Crea el test suite.
 **/
#define TEST_SUITE_BEGIN(X) class X : public INHERITANCE{};
/**
 * @def TEST_METHOD
 * @param X nombre de la clase test
 * @param Y nombre de metodo test
 * @brief Añade y ejecuta el test Y.
 **/			
#define TEST_METHOD(X,Y) TEST_F(X,Y){Y();}
/**
 * @def TEST_SUITE_END()
 * @brief No ejecuta codigo, da logica e intuicion a la escritura de tests.
 **/
#define TEST_SUITE_END() 
/**
 * @def MAIN
 * @brief Define la cabecera de la funcion main
 **/
#define MAIN main(int argc, char **argv)
/**
 * @def RUN_TESTS()
 * @brief Define y ejecuta el codigo de la funcion main que ejecutara la aplicacion de test.
 **/
#define RUN_TESTS() ::testing::InitGoogleTest(&argc, argv); \
			return RUN_ALL_TESTS();
#endif

#ifdef CPPUNIT_TEST_ENABLED
#define DELTA 0.005
#define CHECK_EQ_INT(X,Y) CPPUNIT_ASSERT_EQUAL((float) X,(float) Y)
#define CHECK_EQ_FLOAT(X,Y) CPPUNIT_ASSERT_DOUBLES_EQUAL(X,Y,DELTA)
#define CHECK_NE(X,Y) CPPUNIT_ASSERT(X!=Y)
#define CHECK_LT(X,Y) CPPUNIT_ASSERT(X<Y)
#define CHECK_LE(X,Y) CPPUNIT_ASSERT(X<=Y)
#define CHECK_GT(X,Y) CPPUNIT_ASSERT(X>Y)
#define CHECK_GE(X,Y) CPPUNIT_ASSERT(X>=Y)
#define CHECK_STREQ(X,Y) CPPUNIT_ASSERT(X==Y)
#define CHECK_STRNE(X,Y) CPPUNIT_ASSERT(X!=Y)
#define CHECK_BOOLEAN_TRUE(X) CPPUNIT_ASSERT(X)
#define CHECK_BOOLEAN_FALSE(X) CPPUNIT_ASSERT(!X)
#define CHECK_NULL_POINTER(X) CPPUNIT_ASSERT(X==nullptr)
#define INHERITANCE CppUnit::TestCase
#define TEST_SUITE_BEGIN(X) class X : public INHERITANCE{ \
				CPPUNIT_TEST_SUITE(X); \
				CPPUNIT_TEST_SUITE_END(); \
			    };\
			    CPPUNIT_TEST_SUITE_REGISTRATION(X);	
			
#define TEST_METHOD(X,Y) class X##Y : public X{ \
			 public: \
				CPPUNIT_TEST_SUB_SUITE(X##Y,X);\
				CPPUNIT_TEST(run##Y); \
 				CPPUNIT_TEST_SUITE_END(); \
				void run##Y(){Y();};\
			 }; \
			 CPPUNIT_TEST_SUITE_REGISTRATION(X##Y);
#define TEST_SUITE_END() 
#define MAIN main(int argc, char *argv[])
#define RUN_TESTS() CppUnit::TestResult testresult; \
			CppUnit::TestResultCollector collectedResults; \
			testresult.addListener(&collectedResults); \
			CppUnit::BriefTestProgressListener progress; \
			testresult.addListener(&progress); \
			CppUnit::TestRunner runner; \
			runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest()); \
			runner.run(testresult); \
			CppUnit::CompilerOutputter compilerOutputter(&collectedResults,std::cerr); \
			compilerOutputter.write(); \
			return collectedResults.wasSuccessful() ? 0 : 1;			
#endif

