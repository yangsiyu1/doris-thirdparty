#pragma once

#include <stdint.h>

#include "CLucene/debug/error.h"

CL_NS_DEF2(analysis, standard95)

class Character {
public:
    static inline bool isHighSurrogate(wchar_t ch) {
        return ch >= MIN_HIGH_SURROGATE && ch < (MAX_HIGH_SURROGATE + 1);
    }

    static inline bool isLowSurrogate(wchar_t ch) {
        return ch >= MIN_LOW_SURROGATE && ch < (MAX_LOW_SURROGATE + 1);
    }

    static inline int32_t codePointAt(const wchar_t* a, int32_t size, int32_t index,
                                      int32_t limit) {
        if (index >= limit || index < 0 || limit > size) {
            _CLTHROWA(CL_ERR_IllegalArgument, "codePointAt parser errror");
        }
        return codePointAtImpl(a, index, limit);
    }

    static inline int32_t codePointAtImpl(const wchar_t* a, int32_t index, int32_t limit) {
        wchar_t c1 = a[index];
        if (isHighSurrogate(c1) && ++index < limit) {
            wchar_t c2 = a[index];
            if (isLowSurrogate(c2)) {
                return toCodePoint(c1, c2);
            }
        }
        return c1;
    }

    static inline int32_t charCount(int32_t codePoint) {
        return codePoint >= MIN_SUPPLEMENTARY_CODE_POINT ? 2 : 1;
    }

    static inline int32_t toCodePoint(wchar_t high, wchar_t low) {
        return ((high << 10) + low) +
               (MIN_SUPPLEMENTARY_CODE_POINT - (MIN_HIGH_SURROGATE << 10) - MIN_LOW_SURROGATE);
    }

    static inline int32_t utf8Length(uint8_t ch) {
        if ((ch & 0x80) == 0x00) return 1;
        if ((ch & 0xE0) == 0xC0) return 2;
        if ((ch & 0xF0) == 0xE0) return 3;
        if ((ch & 0xF8) == 0xF0) return 4;
        _CLTHROWA(CL_ERR_IllegalArgument, "utf8Length parser errror");
    }

    static inline int32_t decodeCodepoint(const uint8_t* bytes, int32_t length) {
        switch (length) {
        case 1:
            return (bytes[0] & 0x7F);
        case 2:
            return (bytes[0] & 0x1F) << 6 | (bytes[1] & 0x3F);
        case 3:
            return (bytes[0] & 0x0F) << 12 | (bytes[1] & 0x3F) << 6 | (bytes[2] & 0x3F);
        case 4:
            return (bytes[0] & 0x07) << 18 | (bytes[1] & 0x3F) << 12 | (bytes[2] & 0x3F) << 6 |
                   (bytes[3] & 0x3F);
        default:
            _CLTHROWA(CL_ERR_IllegalArgument, "decodeCodepoint parser errror");
        }
    }

private:
    static constexpr int32_t MIN_HIGH_SURROGATE = 0xD800;
    static constexpr int32_t MAX_HIGH_SURROGATE = 0xDBFF;
    static constexpr int32_t MIN_LOW_SURROGATE = 0xDC00;
    static constexpr int32_t MAX_LOW_SURROGATE = 0xDFFF;

    static constexpr int32_t MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;
};

CL_NS_END2