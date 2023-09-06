#pragma once

#include <memory>

#include "CLucene/util/v1/Reader.h"

using namespace lucene::util::v1;

namespace lucene::analysis {

class CharFilter : public Reader {
public:
    CharFilter(Reader* input) : input_(input) {}

    virtual ~CharFilter() {
        if (input_) {
            delete input_;
            input_ = nullptr;
        }
    }

protected:
    Reader* input_ = nullptr;
};

} // namespace lucene::analysis