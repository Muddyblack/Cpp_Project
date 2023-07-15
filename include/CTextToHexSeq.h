#ifndef CTEXTTOHEXSEQ_H
#define CTEXTTOHEXSEQ_H

#include <CTextToCPP.h>

class CTextToHexSeq : public CTextToCPP
{
public:
    std::string toHex(std::string inputString);

private:
};

#endif // CTEXTTOHEXSEQ_H