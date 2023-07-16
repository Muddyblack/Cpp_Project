#ifndef CTEXTTOESCSEQ_H
#define CTEXTTOESCSEQ_H

#include <CTextToCPP.h>

class CTextToEscSeq : public CTextToCPP
{
public:
    CTextToEscSeq(const VariableStruct &variable, const ParamStruct &parameter);
    ~CTextToEscSeq();

private:
    std::string convert(std::string inputString) override;
};

#endif // CTEXTTOESCSEQ_H