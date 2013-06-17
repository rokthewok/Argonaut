#ifndef  BOOLEANFORMATEXCEPTION_H
#define  BOOLEANFORMATEXCEPTION_H
#include <stdexcept>

class BooleanFormatException : public std::logic_error {
	public:
		BooleanFormatException()
					: std::logic_error( "" ), m_message( "BooleanFormatException" ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		const char * m_message;
};

#endif   /* ----- #ifndef BOOLEANFORMATEXCEPTION_H  ----- */
