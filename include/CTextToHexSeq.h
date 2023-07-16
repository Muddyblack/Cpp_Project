#ifndef CTEXTTOHEXSEQ_H
#define CTEXTTOHEXSEQ_H

#include <CTextToCPP.h>

class CTextToHexSeq : public CTextToCPP
{
public:
    std::string convert(std::string inputString, int lineNumber);

private:
};

#endif // CTEXTTOHEXSEQ_H