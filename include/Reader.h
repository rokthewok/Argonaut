#ifndef READER_H
#define READER_H
#include <istream>
#include <string>

namespace Argonaut {
class Reader {
public:
    explicit Reader( const std::string & str );
    explicit Reader( std::istream * in );
    ~Reader();
    virtual char getNextChar();
    virtual char peekNextChar();
private:
    std::istream * m_in;
    bool m_isStringStream;
};
} // namespace Argonaut

#endif
