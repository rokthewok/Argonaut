/*
 * =====================================================================================
 *
 *       Filename:  BaseTests.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2013 07:51:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "BaseTests.h"
#include <iostream>

BaseTests::BaseTests() {

}

void BaseTests::printResults( std::string testName, bool result, bool end ) {
	static unsigned int passed = 0;
	static unsigned int total = 0;

	if( result ) {
		std::cout << testName << ": pass" << std::endl;
		passed++;
	} else {
		std::cout << testName << ": fail" << std::endl;
	}

	total++;

	if( end ) {
		std::cout << passed << " of " << total << " tests passed." << std::endl;
	}
}

