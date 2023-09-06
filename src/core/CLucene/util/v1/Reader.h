#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

#include "CLucene/debug/error.h"

namespace lucene::util::v1 {

class Reader {
public:
    Reader() = default;
    virtual ~Reader() = default;

    virtual void init(char* buf, size_t size) = 0;
    virtual int32_t read(char* buf, int32_t off, int32_t len) = 0;
    virtual int32_t read() = 0;
    virtual size_t size() {
        _CLTHROWA(CL_ERR_UnsupportedOperation, "UnsupportedOperationException Reader::size");
    }
    virtual void close() {
        _CLTHROWA(CL_ERR_UnsupportedOperation, "UnsupportedOperationException Reader::close");
    }
};

} // namespace lucene::util::v1