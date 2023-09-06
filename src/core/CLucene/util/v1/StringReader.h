#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>

#include "CLucene/util/v1/Reader.h"

namespace lucene::util::v1 {

class StringReader : public Reader {
public:
    StringReader() = default;
    StringReader(const char* buf, size_t size) : buf_(buf), size_(size) {}

    virtual ~StringReader() = default;

    void init(char* buf, size_t size) override {
        buf_ = buf;
        pos_ = 0;
        size_ = size;
    }

    int32_t read(char* buf, int32_t off, int32_t len) override {
        if (size_ == 0) return 0;
        if (pos_ >= size_) return -1;
        int32_t n = std::min(static_cast<int32_t>(size_ - pos_), len);
        std::copy_n(buf_ + pos_, n, buf + off);
        pos_ += n;
        return n;
    }

    int32_t read() override {
        if (size_ == 0) return 0;
        if (pos_ >= size_) return -1;
        return buf_[pos_++];
    }

    size_t size() override { return size_; }

    void close() override {
        buf_ = nullptr;
        pos_ = 0;
        size_ = 0;
    }

private:
    const char* buf_ = nullptr;
    int32_t pos_ = 0;
    size_t size_ = 0;
};

} // namespace lucene::util::v1