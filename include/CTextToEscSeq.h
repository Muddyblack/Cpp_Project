#ifndef CTEXTTOESCSEQ_H
#define CTEXTTOESCSEQ_H

#include <CTextToCPP.h>

class CTextToEscSeq : public CTextToCPP
{
public:
    std::string toEsc(std::string inputString);

private:
};

#endif // CTEXTTOESCSEQ_H