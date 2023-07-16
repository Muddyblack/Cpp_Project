#ifndef CTEXTTOESCSEQ_H
#define CTEXTTOESCSEQ_H

#include <CTextToCPP.h>

class CTextToEscSeq : public CTextToCPP
{
public:
    std::string convert(std::string inputString, int lineNumber);

private:
};

#endif // CTEXTTOESCSEQ_H