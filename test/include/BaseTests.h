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
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

};

#endif   /* ----- #ifndef BASETESTS_H  ----- */
