#ifndef  STRINGFORMATEXCEPTION_H
#define  STRINGFORMATEXCEPTION_H
#include <stdexcept>

class StringFormatException : public std::logic_error {
	public:
		StringFormatException()
					: std::logic_error( "" ), m_message( "StringFormatException" ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		const char * m_message;
};

#endif   /* ----- #ifndef STRINGFORMATEXCEPTION_H  ----- */
