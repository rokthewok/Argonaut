#ifndef SYNTAX_EXCEPTION_H
#define SYNTAX_EXCEPTION_H
#include <stdexcept>
#include <string>

class SyntaxException : public std::logic_error {
	public:
		SyntaxException()
					: std::logic_error( "A SyntaxException has occurred in: " ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		char * m_message;
};

#endif
