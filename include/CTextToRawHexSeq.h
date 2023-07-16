#ifndef CTEXTTORAWHEXSEQ_H
#define CTEXTTORAWHEXSEQ_H

#include <CTextToCPP.h>

class CTextToRawHexSeq : public CTextToCPP
{
public:
    std::string convert(std::string inputString, int lineNumber);

private:
};

#endif // CTEXTTORAWHEXSEQ_H