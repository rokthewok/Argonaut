#ifndef  MEMBERPARSINGEXCEPTION_H
#define  MEMBERPARSINGEXCEPTION_H
#include <stdexcept>

namespace Argonaut {
class MemberParsingException : public std::logic_error {
	public:
		MemberParsingException()
					: std::logic_error( "" ), m_message( "MemberParsingException" ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		const char * m_message;
};
} // namespace Argonaut

#endif   /* ----- #ifndef MEMBERPARSINGEXCEPTION_H  ----- */
