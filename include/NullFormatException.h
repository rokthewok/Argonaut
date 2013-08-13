#ifndef  NULLFORMATEXCEPTION_H
#define  NullFORMATEXCEPTION_H
#include <stdexcept>

namespace Argonaut {
class NullFormatException : public std::logic_error {
	public:
		NullFormatException()
					: std::logic_error( "" ), m_message( "NullFormatException" ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		const char * m_message;
};
} // namespace Argonaut

#endif   /* ----- #ifndef NULLFORMATEXCEPTION_H  ----- */
