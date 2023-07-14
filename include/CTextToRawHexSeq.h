#ifndef CTEXTTORAWHEXSEQ_H
#define CTEXTTORAWHEXSEQ_H

#include <CTextToCPP.h>

class CTextToRawHexSeq : public CTextToCPP
{
public:
    CTextToRawHexSeq();
    ~CTextToRawHexSeq();
    std::string toRawHex(std::string inputString);

private:
};

#endif // CTEXTTORAWHEXSEQ_H