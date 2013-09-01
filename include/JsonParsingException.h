#ifndef  JSONPARSINGEXCEPTION_H
#define  JSONPARSINGEXCEPTION_H
#include <stdexcept>

namespace Argonaut {
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
} // namespace Argonaut

#endif   /* ----- #ifndef JSONPARSINGEXCEPTION_H  ----- */
