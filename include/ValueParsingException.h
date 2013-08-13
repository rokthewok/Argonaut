#ifndef  VALUEPARSINGEXCEPTION_H
#define  VALUEPARSINGEXCEPTION_H
#include <stdexcept>

namespace Argonaut {
class ValueParsingException : public std::logic_error {
	public:
		ValueParsingException()
					: std::logic_error( "" ), m_message( "ValueParsingException" ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		const char * m_message;
};
} // namespace Argonaut

#endif   /* ----- #ifndef VALUEPARSINGEXCEPTION_H  ----- */
