#pragma once

#include <string>
#include <utility>
#include <vector>

#include "CLucene/analysis/CharFilter.h"
#include "CLucene/util/v1/StringReader.h"

namespace lucene::analysis {

std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = s.find(delimiter);
    while (end != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

class CharReplaceCharFilter : public CharFilter {
public:
    CharReplaceCharFilter(Reader* in, const std::string& pattern,
                          const std::string& replacement, const std::string& separator = " ")
            : CharFilter(in), _replacement(replacement) {
        patterns = split(pattern, separator);
    }

    virtual ~CharReplaceCharFilter() = default;

    void init(char* buf, size_t size) override {
        input_->init(buf, size);
        fill();
    }

    int32_t read(char* buf, int32_t off, int32_t len) override {
        return _transformedInput.read(buf, off, len);
    }

    int32_t read() override { return _transformedInput.read(); }

private:
    void fill() {
        _buf.resize(input_->size());
        input_->read(_buf.data(), 0, _buf.size());
        processPattern(_buf);
        _transformedInput.init(_buf.data(), _buf.size());
    }

    void processPattern(std::string& buf) {
        for (const auto& pattern : patterns) {
            size_t pos = 0;
            while ((pos = buf.find(pattern, pos)) != std::string::npos) {
                buf.replace(pos, pattern.length(), _replacement);
                pos += _replacement.length();
            }
        }
    }

private:
    std::string _replacement;
    std::vector<std::string> patterns;

    std::string _buf;
    StringReader _transformedInput;
};

} // namespace lucene::analysis