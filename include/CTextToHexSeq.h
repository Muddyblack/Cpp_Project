#ifndef CTEXTTOHEXSEQ_H
#define CTEXTTOHEXSEQ_H

#include <CTextToCPP.h>

class CTextToHexSeq : public CTextToCPP
{
public:
    CTextToHexSeq(const VariableStruct &variable, const ParamStruct &parameter);
    ~CTextToHexSeq();

private:
    std::string convert(std::string inputString, int varLine, std::string inputFile, std::string nl) override;
};

#endif // CTEXTTOHEXSEQ_H