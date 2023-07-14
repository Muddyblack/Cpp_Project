#ifndef CTEXTTOESCSEQ_H
#define CTEXTTOESCSEQ_H

#include <CTextToCPP.h>

class CTextToEscSeq : public CTextToCPP
{
public:
    CTextToEscSeq();
    ~CTextToEscSeq();
    std::string toEsc(std::string inputString);

private:
};

#endif // CTEXTTOESCSEQ_H