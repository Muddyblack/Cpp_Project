#ifndef CTEXTTOHEXSEQ_H
#define CTEXTTOHEXSEQ_H

#include <CTextToCPP.h>

class CTextToHexSeq : public CTextToCPP
{
public:
    CTextToHexSeq(const VariableStruct &variable, const ParamStruct &parameter);
    ~CTextToHexSeq();

private:
    std::string convert(std::string inputString) override;
};

#endif // CTEXTTOHEXSEQ_H