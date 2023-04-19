#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "CLucene/analysis/AnalysisHeader.h"
#include "StandardTokenizerImpl.h"
#include "CLucene/util/stringUtil.h"

CL_NS_USE(util)
CL_NS_DEF2(analysis, standard95)

template <class T>
class CLUCENE_EXPORT StandardTokenizer : public Tokenizer {
public:
    StandardTokenizer(CL_NS(util)::Reader* reader) : reader_(reader) { init(); }

    virtual ~StandardTokenizer() {
        if (scanner_ != nullptr) delete scanner_;
        scanner_ = nullptr;
    }

    Token* next(Token* token) override {
        int32_t tokenType = scanner_->getNextToken();

        if (tokenType == StandardTokenizerImpl<T>::YYEOF) {
            return nullptr;
        }

        if (scanner_->yylength() <= maxTokenLength_) {
            scanner_->getText(term);
            if (tokenType == StandardTokenizerImpl<T>::WORD_TYPE) {
                std::transform(term.begin(), term.end(), (char*)term.begin(),
                               [](uint8_t c) { return to_lower(c); });
                // to_lower((const uint8_t*)term.data(), term.size(), (uint8_t*)term.data());
            }
            token->set(term.data(), 0, term.size());
            return token;
        } else {
            skippedPositions_++;
        }
        return nullptr;
    };

    void reset(CL_NS(util)::Reader* input) override {
        Tokenizer::reset(input);
        scanner_->yyreset(reader_);
        skippedPositions_ = 0;
    };

    void close() override {
        Tokenizer::close();
        scanner_->yyclose();
    }

private:
    void init() { scanner_ = new StandardTokenizerImpl<T>(reader_); }

private:
    CL_NS(util)::Reader* reader_ = nullptr;
    StandardTokenizerImpl<T>* scanner_ = nullptr;

    std::basic_string_view<T> term;

    int32_t skippedPositions_ = 0;
    int32_t maxTokenLength_ = 255;
};

CL_NS_END2