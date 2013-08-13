#include <iostream>
#include "Argonaut.h"

void printHelp();

int main( int argc, char ** argv ) {
	if( argc < 2 ) {
		printHelp();
		return 0;
	}

	if( argv[1][0] != '-' ) {
		std::cout << "improper usage. Use -h flag for help." << std::endl;
		return -1;
	}

	Argonaut::Argonaut argonaut;
	if( argv[1][1] == 'i' ) {
		argonaut.runInteractiveShell();
	} else if( argv[1][1] == 'd' ) {
		argonaut.runExampleUsage();
	} else if( argv[1][1] == 'h' ) {
		printHelp();
	} else {
		std::cout << "improper usage. Use -h flag for help." << std::endl;
		return -1;
	}

	return 0;
}

void printHelp() {
	std::cout << "Argonaut usage: " << std::endl;
	std::cout << "\t-i\tinteractive shell mode" << std::endl;
	std::cout << "\t-d\tdemo (example usage) mode" << std::endl;
}
