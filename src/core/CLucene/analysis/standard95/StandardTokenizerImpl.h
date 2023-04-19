#pragma once

#include <stdint.h>
#include <string.h>

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

#include "CLucene/SharedHeader.h"
#include "CLucene/util/CLStreams.h"

CL_NS_DEF2(analysis, standard95)

template <class T>
class StandardTokenizerImpl {
public:
    static constexpr int32_t YYEOF = -1;

private:
    int32_t ZZ_BUFFERSIZE = 255;

public:
    static constexpr int32_t YYINITIAL = 0;

private:
    static const std::vector<int32_t> ZZ_LEXSTATE;

    static const std::vector<int32_t> ZZ_CMAP_TOP;

    static const wchar_t ZZ_CMAP_TOP_PACKED_0[];

private:
    static std::vector<int32_t> zzUnpackcmap_top();

    static int32_t zzUnpackcmap_top(const wchar_t* packed, int32_t offset,
                                    std::vector<int32_t>& result);

    static const std::vector<int32_t> ZZ_CMAP_BLOCKS;

    static const wchar_t ZZ_CMAP_BLOCKS_PACKED_0[];

    static std::vector<int32_t> zzUnpackcmap_blocks();

    static int32_t zzUnpackcmap_blocks(const wchar_t* packed, int32_t offset,
                                       std::vector<int32_t>& result);

    static const std::vector<int32_t> ZZ_ACTION;

    static const wchar_t ZZ_ACTION_PACKED_0[];

    static std::vector<int32_t> zzUnpackAction();

    static int32_t zzUnpackAction(const wchar_t* packed, int32_t offset,
                                  std::vector<int32_t>& result);

    static const std::vector<int32_t> ZZ_ROWMAP;

    static const wchar_t ZZ_ROWMAP_PACKED_0[];

    static std::vector<int32_t> zzUnpackRowMap();

    static int32_t zzUnpackRowMap(const wchar_t* packed, int32_t offset,
                                  std::vector<int32_t>& result);

    static const std::vector<int32_t> ZZ_TRANS;

    static const wchar_t ZZ_TRANS_PACKED_0[];

    static std::vector<int32_t> zzUnpackTrans();

    static int32_t zzUnpackTrans(const wchar_t* packed, int32_t offset,
                                 std::vector<int32_t>& result);

    static constexpr int32_t ZZ_UNKNOWN_ERROR = 0;
    static constexpr int32_t ZZ_NO_MATCH = 1;
    static constexpr int32_t ZZ_PUSHBACK_2BIG = 2;

    static const std::vector<std::string> ZZ_ERROR_MSG;

    static const std::vector<int32_t> ZZ_ATTRIBUTE;

    static const wchar_t ZZ_ATTRIBUTE_PACKED_0[];

    static std::vector<int32_t> zzUnpackAttribute();

    static int32_t zzUnpackAttribute(const wchar_t* packed, int32_t offset,
                                     std::vector<int32_t>& result);

    int32_t zzState = 0;

    int32_t zzLexicalState = YYINITIAL;

    std::vector<T> zzBuffer;

    int32_t zzMarkedPos = 0;

    int32_t zzCurrentPos = 0;

    int32_t zzStartRead = 0;

    int32_t zzEndRead = 0;

    bool zzAtEOF = false;

    int32_t zzFinalHighSurrogate = 0;

    int32_t yyline = 0;

    int32_t yycolumn = 0;

    long long yychar_Conflict = 0;

    bool zzAtBOL = true;

    bool zzEOFDone = false;

public:
    static constexpr int32_t WORD_TYPE = 0;
    static constexpr int32_t NUMERIC_TYPE = 1;
    static constexpr int32_t SOUTH_EAST_ASIAN_TYPE = 2;
    static constexpr int32_t IDEOGRAPHIC_TYPE = 3;
    static constexpr int32_t HIRAGANA_TYPE = 4;
    static constexpr int32_t KATAKANA_TYPE = 5;
    static constexpr int32_t HANGUL_TYPE = 6;
    static constexpr int32_t EMOJI_TYPE = 7;

    inline void getText(std::basic_string_view<T>& v) {
        v = std::basic_string_view<T>(zzBuffer.data() + zzStartRead, zzMarkedPos - zzStartRead);
    }

    StandardTokenizerImpl(CL_NS(util)::Reader* reader);

private:
    inline int32_t zzCMap(int32_t input) {
        int32_t offset = input & 255;
        return offset == input ? ZZ_CMAP_BLOCKS[offset]
                               : ZZ_CMAP_BLOCKS[ZZ_CMAP_TOP[input >> 8] | offset];
    }

    bool zzRefill();

public:
    void yyclose();

    void yyreset(CL_NS(util)::Reader* reader);

private:
    void yyResetPosition();

public:
    inline int32_t yylength() { return zzMarkedPos - zzStartRead; }

private:
    static void zzScanError(int32_t errorCode);

public:
    int32_t getNextToken();

private:
    CL_NS(util)::Reader* zzReader = nullptr;
};

CL_NS_END2
