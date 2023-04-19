#pragma once

#include "CLucene/analysis/AnalysisHeader.h"
#include "StandardTokenizer.h"

CL_NS_DEF2(analysis, standard95)

template <typename T>
class CLUCENE_EXPORT StandardAnalyzer : public Analyzer {
public:
    StandardAnalyzer() = default;
    virtual ~StandardAnalyzer() = default;

    TokenStream* tokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader) override {
        return _CLNEW StandardTokenizer<T>(reader);
    }

    TokenStream* reusableTokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader) override {
        auto* tokenizer = static_cast<Tokenizer*>(getPreviousTokenStream());
        if (tokenizer == nullptr) {
            tokenizer = _CLNEW StandardTokenizer<T>(reader);
            setPreviousTokenStream(tokenizer);
        } else
            tokenizer->reset(reader);
        return tokenizer;
    };
};

CL_NS_END2
