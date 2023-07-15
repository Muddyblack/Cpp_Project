#ifndef CTEXTTORAWHEXSEQ_H
#define CTEXTTORAWHEXSEQ_H

#include <CTextToCPP.h>

class CTextToRawHexSeq : public CTextToCPP
{
public:
    CTextToRawHexSeq(const VariableStruct &variable);
    ~CTextToRawHexSeq();

private:
    std::string convert(std::string inputString) override;
};

#endif // CTEXTTORAWHEXSEQ_H