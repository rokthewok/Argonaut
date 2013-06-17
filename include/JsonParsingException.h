#ifndef  JSONPARSINGEXCEPTION_H
#define  JSONPARSINGEXCEPTION_H
#include <stdexcept>

class JsonParsingException : public std::logic_error {
	public:
		JsonParsingException()
					: std::logic_error( "" ), m_message( "JsonParsingException" ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		const char * m_message;
};

#endif   /* ----- #ifndef JSONPARSINGEXCEPTION_H  ----- */
