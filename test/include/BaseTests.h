#ifndef  BASETESTS_H
#define  BASETESTS_H
#include <string>

/*
 * =====================================================================================
 *        Class:  BaseTests
 *  Description:  
 * =====================================================================================
 */
class BaseTests {
	public:
		BaseTests();                             /* constructor */
		void printResults( std::string testName, bool result, bool end );
		virtual void runTests() = 0;
	private:
		int m_passed;
		int m_total;
};

#endif   /* ----- #ifndef BASETESTS_H  ----- */
