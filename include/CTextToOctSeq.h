#ifndef CTEXTTOOCTSEQ_H
#define CTEXTTOOCTSEQ_H

#include <CTextToCPP.h>

class CTextToOctSeq : public CTextToCPP
{
public:
    CTextToOctSeq(const VariableStruct &variable, const ParamStruct &parameter);
    ~CTextToOctSeq();

private:
    std::string convert(std::string inputString) override;
};

#endif // CTEXTTOOCTSEQ_H