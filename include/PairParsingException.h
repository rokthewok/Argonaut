#ifndef  PAIRPARSINGEXCEPTION_H
#define  PAIRPARSINGEXCEPTION_H
#include <stdexcept>

class PairParsingException : public std::logic_error {
	public:
		PairParsingException()
					: std::logic_error( "" ), m_message( "PairParsingException" ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		const char * m_message;
};

#endif   /* ----- #ifndef PAIRPARSINGEXCEPTION_H  ----- */
