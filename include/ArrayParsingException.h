#ifndef  ARRAYPARSINGEXCEPTION_H
#define  ARRAYPARSINGEXCEPTION_H
#include <stdexcept>

class ArrayParsingException : public std::logic_error {
	public:
		ArrayParsingException()
					: std::logic_error( "" ), m_message( "ArrayParsingException" ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		const char * m_message;
};

#endif   /* ----- #ifndef ARRAYPARSINGEXCEPTION_H  ----- */
