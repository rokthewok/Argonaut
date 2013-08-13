#ifndef SYNTAX_EXCEPTION_H
#define SYNTAX_EXCEPTION_H
#include <stdexcept>

namespace Argonaut {
class SyntaxException : public std::logic_error {
	public:
		SyntaxException( const char * method )
					: std::logic_error( method ), m_message( method ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		const char * m_message;
};
} // namespace Argonaut

#endif
