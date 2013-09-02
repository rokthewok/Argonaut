Argonaut - a JSON parser in C++
===============================

**Compiling:**
Compile by calling `make` in the top level directory of the project. Calling `make test` will create the test executable for the project. Calling `make clean` will clear the compiled binaries and output files.

To execute the program, call:

	./argonaut [-idh]
		-i	interactive shell; enter json strings and see the output. 'q' quits.
		-d	run the demo (example usage) script. The code is listed below.
		-h	help.

Example usage code:

	std::string json( "{ \"name\" : \"Malcolm Reynolds\" , \"vehicle\" : \"Firefly\" , \"age\" : 31 , \"wanted\" : true }" );

	JsonParser parser;

	JsonObject * object = parser.parseJson( json );

	const std::vector<JsonValue *> members = object->getMembers();
	// alternatively, use:
	// auto members = object->getMembers();

	for( auto value : members ) {
	    if( value->getName() == "name" && value->isString() ) {
		std::cout << value->getString() << std::endl;
	    } else if( value->isBoolean() ) {
		if( value->getBoolean() ) {
		    std::cout << "Mal is a wanted man!" << std::endl;
		} else {
		    std::cout << "Mal is not wanted" << std::endl;
		}
	    } else if( value->getName() == "age" ) {
		std::cout << "Mal is " << value->getInteger() << " years old." << std::endl;
	    } else if( value->getName() == "vehicle" ) {
		std::cout << "Mal drives a " << value->getString() << ". Sexy." << std::endl;
	    }
	}

	delete object;

*see argonaut.cpp for the example usage in play*

TODO:
----

*   Change JSON Objects to behave more like STL containers, rather than exposing the underlying representation
*	Provide more robust testing for the entire system
*	Create shared and static libraries
*	Add better documentation for the client
