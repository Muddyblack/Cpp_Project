#ifndef CTEXTTOOCTSEQ_H
#define CTEXTTOOCTSEQ_H

#include <CTextToCPP.h>

class CTextToOctSeq : public CTextToCPP
{
public:
    std::string convert(std::string inputString, int lineNumber);

private:
};

#endif // CTEXTTOOCTSEQ_H