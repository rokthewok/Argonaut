#ifndef  NUMBERFORMATEXCEPTION_H
#define  NUMBERFORMATEXCEPTION_H
#include <stdexcept>

namespace Argonaut {
class NumberFormatException : public std::logic_error {
	public:
		NumberFormatException()
					: std::logic_error( "" ), m_message( "NumberFormatException" ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		const char * m_message;
};
} // namespace Argonaut

#endif   /* ----- #ifndef NUMBERFORMATEXCEPTION_H  ----- */
