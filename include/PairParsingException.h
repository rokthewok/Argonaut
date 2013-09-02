#ifndef  PAIRPARSINGEXCEPTION_H
#define  PAIRPARSINGEXCEPTION_H
#include <stdexcept>

namespace Argonaut {
class PairParsingException : public std::logic_error {
public:
    PairParsingException()
            : std::logic_error( "" ), 
              m_message( "PairParsingException" ) { };
    virtual const char *  what() const throw() 
            { return m_message; };
private:
    const char * m_message;
};
} // namespace Argonaut

#endif   /* ----- #ifndef PAIRPARSINGEXCEPTION_H  ----- */
