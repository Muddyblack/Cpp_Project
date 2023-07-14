#ifndef CTEXTTOOCTSEQ_H
#define CTEXTTOOCTSEQ_H

#include <CTextToCPP.h>

class CTextToOctSeq : public CTextToCPP
{
public:
    CTextToOctSeq();
    ~CTextToOctSeq();
    std::string toOct(std::string inputString);

private:
};

#endif // CTEXTTOOCTSEQ_H