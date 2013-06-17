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

BaseTests::BaseTests()
	: m_passed( 0 ),
	  m_total( 0 ) {

}

void BaseTests::printResults( std::string testName, bool result, bool end ) {
	
	if( result ) {
		std::cout << testName << ": pass" << std::endl;
		m_passed++;
	} else {
		std::cout << testName << ": fail" << std::endl;
	}

	m_total++;

	if( end ) {
		std::cout << m_passed << " of " << m_total << " tests passed." << std::endl;
	}
}

