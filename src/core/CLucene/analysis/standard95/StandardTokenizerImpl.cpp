#include "StandardTokenizerImpl.h"

#include "CLucene/debug/error.h"
#include "Character.h"

CL_NS_DEF2(analysis, standard95)

template <class T>
const std::vector<int32_t> StandardTokenizerImpl<T>::ZZ_LEXSTATE = {0, 0};
template <class T>
const std::vector<int32_t> StandardTokenizerImpl<T>::ZZ_CMAP_TOP = zzUnpackcmap_top();
template <class T>
const wchar_t StandardTokenizerImpl<T>::ZZ_CMAP_TOP_PACKED_0[] =
        L"\1\0\1\u0100\1\u0200\1\u0300\1\u0400\1\u0500\1\u0600\1\u0700"
        L"\1\u0800\1\u0900\1\u0a00\1\u0b00\1\u0c00\1\u0d00\1\u0e00\1\u0f00"
        L"\1\u1000\1\u1100\1\u1200\1\u1300\1\u1400\1\u0100\1\u1500\1\u1600"
        L"\1\u1700\1\u1800\1\u1900\1\u1a00\1\u1b00\1\u1c00\1\u0100\1\u1d00"
        L"\1\u1e00\1\u1f00\1\u2000\1\u2100\1\u2200\1\u2300\1\u2400\1\u2500"
        L"\1\u2000\1\u2600\1\u2000\1\u2700\1\u2800\1\u2900\1\u2a00\1\u2b00"
        L"\1\u2c00\1\u2d00\1\u2e00\1\u2f00\31\u3000\1\u3100\121\u3000\1\u3200"
        L"\4\u0100\1\u3300\1\u0100\1\u3400\1\u3500\1\u3600\1\u3700\1\u3800"
        L"\1\u3900\53\u1100\1\u3a00\41\u2000\1\u3000\1\u3b00\1\u3c00\1\u0100"
        L"\1\u3d00\1\u3e00\1\u3f00\1\u4000\1\u4100\1\u4200\1\u4300\1\u4400"
        L"\1\u4500\1\u0100\1\u4600\1\u4700\1\u4800\1\u4900\1\u4a00\1\u4b00"
        L"\1\u4c00\1\u2000\1\u4d00\1\u4e00\1\u4f00\1\u5000\1\u5100\1\u5200"
        L"\1\u5300\1\u5400\1\u5500\1\u5600\1\u5700\1\u5800\1\u2000\1\u5900"
        L"\1\u5a00\1\u5b00\1\u2000\3\u0100\1\u5c00\1\u5d00\1\u5e00\12\u2000"
        L"\4\u0100\1\u5f00\17\u2000\2\u0100\1\u6000\41\u2000\2\u0100\1\u6100"
        L"\1\u6200\2\u2000\1\u6300\1\u6400\100\u2000\1\u6500\1\u6600\12\u2000"
        L"\1\u6700\24\u2000\1\u6800\1\u6900\1\u2000\1\u6a00\1\u6b00\1\u6c00"
        L"\1\u6d00\2\u2000\1\u6e00\5\u2000\1\u6f00\1\u7000\1\u7100\5\u2000"
        L"\1\u7200\1\u7300\4\u2000\1\u7400\1\u2000\1\u7500\1\u7600\1\u7700"
        L"\1\u7800\1\u7900\1\u7a00\1\u7b00\1\u7c00\1\u7d00\1\u7e00\1\u7f00"
        L"\4\u8000\1\u8100\246\u3000\1\u8200\20\u3000\1\u8300\1\u8400\25\u3000"
        L"\1\u8500\34\u3000\1\u8600\14\u2000\2\u3000\1\u8700\u0b05\u2000\1\u8800"
        L"\1\u8900\u02fe\u2000";

template <class T>
std::vector<int32_t> StandardTokenizerImpl<T>::zzUnpackcmap_top() {
    std::vector<int32_t> result(4352);
    int32_t offset = 0;
    offset = zzUnpackcmap_top(ZZ_CMAP_TOP_PACKED_0, offset, result);
    return result;
}

template <class T>
int32_t StandardTokenizerImpl<T>::zzUnpackcmap_top(const wchar_t* packed, int32_t offset,
                                                   std::vector<int32_t>& result) {
    int32_t i = 0;
    int32_t j = offset;
    while (i < 356) {
        int32_t count = packed[i++];
        int32_t value = packed[i++];
        do {
            result[j++] = value;
        } while (--count > 0);
    }
    return j;
}

template <class T>
const std::vector<int32_t> StandardTokenizerImpl<T>::ZZ_CMAP_BLOCKS = zzUnpackcmap_blocks();
template <class T>
const wchar_t StandardTokenizerImpl<T>::ZZ_CMAP_BLOCKS_PACKED_0[] =
        L"\42\0\1\1\1\2\3\0\1\3\2\0\1\2\1\0"
        L"\1\4\1\0\1\5\1\0\12\6\1\7\1\4\5\0"
        L"\32\10\4\0\1\11\1\0\32\10\56\0\1\12\1\10"
        L"\2\0\1\13\1\12\6\0\1\10\1\0\1\7\2\0"
        L"\1\10\5\0\27\10\1\0\37\10\1\0\u01e0\10\6\0"
        L"\7\10\7\0\24\10\160\13\5\10\1\0\2\10\2\0"
        L"\4\10\1\4\1\10\6\0\1\10\1\7\3\10\1\0"
        L"\1\10\1\0\24\10\1\0\123\10\1\0\213\10\1\0"
        L"\7\13\246\10\1\0\46\10\2\0\1\10\1\0\2\10"
        L"\1\0\1\10\1\0\51\10\1\4\7\0\55\13\1\0"
        L"\1\13\1\0\2\13\1\0\2\13\1\0\1\13\10\0"
        L"\33\14\4\0\4\14\1\10\1\7\13\0\6\13\6\0"
        L"\2\4\2\0\13\13\1\0\1\13\3\0\53\10\25\13"
        L"\12\15\1\0\1\15\1\4\1\0\2\10\1\13\143\10"
        L"\1\0\1\10\10\13\1\0\6\13\2\10\2\13\1\0"
        L"\4\13\2\10\12\15\3\10\2\0\1\10\17\0\1\13"
        L"\1\10\1\13\36\10\33\13\2\0\131\10\13\13\1\10"
        L"\16\0\12\15\41\10\11\13\2\10\2\0\1\4\1\0"
        L"\1\10\2\0\1\13\2\0\26\10\4\13\1\10\11\13"
        L"\1\10\3\13\1\10\5\13\22\0\31\10\3\13\4\0"
        L"\13\10\65\0\25\10\1\0\10\10\25\0\61\13\66\10"
        L"\3\13\1\10\22\13\1\10\7\13\12\10\2\13\2\0"
        L"\12\15\1\0\20\10\3\13\1\0\10\10\2\0\2\10"
        L"\2\0\26\10\1\0\7\10\1\0\1\10\3\0\4\10"
        L"\2\0\1\13\1\10\7\13\2\0\2\13\2\0\3\13"
        L"\1\10\10\0\1\13\4\0\2\10\1\0\3\10\2\13"
        L"\2\0\12\15\2\10\12\0\1\10\1\0\1\13\2\0"
        L"\3\13\1\0\6\10\4\0\2\10\2\0\26\10\1\0"
        L"\7\10\1\0\2\10\1\0\2\10\1\0\2\10\2\0"
        L"\1\13\1\0\5\13\4\0\2\13\2\0\3\13\3\0"
        L"\1\13\7\0\4\10\1\0\1\10\7\0\12\15\2\13"
        L"\3\10\1\13\13\0\3\13\1\0\11\10\1\0\3\10"
        L"\1\0\26\10\1\0\7\10\1\0\2\10\1\0\5\10"
        L"\2\0\1\13\1\10\10\13\1\0\3\13\1\0\3\13"
        L"\2\0\1\10\17\0\2\10\2\13\2\0\12\15\11\0"
        L"\1\10\6\13\1\0\3\13\1\0\10\10\2\0\2\10"
        L"\2\0\26\10\1\0\7\10\1\0\2\10\1\0\5\10"
        L"\2\0\1\13\1\10\7\13\2\0\2\13\2\0\3\13"
        L"\10\0\2\13\4\0\2\10\1\0\3\10\2\13\2\0"
        L"\12\15\1\0\1\10\20\0\1\13\1\10\1\0\6\10"
        L"\3\0\3\10\1\0\4\10\3\0\2\10\1\0\1\10"
        L"\1\0\2\10\3\0\2\10\3\0\3\10\3\0\14\10"
        L"\4\0\5\13\3\0\3\13\1\0\4\13\2\0\1\10"
        L"\6\0\1\13\16\0\12\15\20\0\5\13\10\10\1\0"
        L"\3\10\1\0\27\10\1\0\20\10\3\0\1\10\7\13"
        L"\1\0\3\13\1\0\4\13\7\0\2\13\1\0\3\10"
        L"\5\0\2\10\2\13\2\0\12\15\20\0\1\10\3\13"
        L"\1\0\10\10\1\0\3\10\1\0\27\10\1\0\12\10"
        L"\1\0\5\10\2\0\1\13\1\10\7\13\1\0\3\13"
        L"\1\0\4\13\7\0\2\13\7\0\1\10\1\0\2\10"
        L"\2\13\2\0\12\15\1\0\2\10\15\0\4\13\1\0"
        L"\10\10\1\0\3\10\1\0\51\10\2\13\1\10\7\13"
        L"\1\0\3\13\1\0\4\13\1\10\5\0\3\10\1\13"
        L"\7\0\3\10\2\13\2\0\12\15\12\0\6\10\2\0"
        L"\2\13\1\0\22\10\3\0\30\10\1\0\11\10\1\0"
        L"\1\10\2\0\7\10\3\0\1\13\4\0\6\13\1\0"
        L"\1\13\1\0\10\13\6\0\12\15\2\0\2\13\15\0"
        L"\60\16\1\17\2\16\7\17\5\0\7\16\10\17\1\0"
        L"\12\15\47\0\2\16\1\0\1\16\1\0\5\16\1\0"
        L"\30\16\1\0\1\16\1\0\12\16\1\17\2\16\11\17"
        L"\1\16\2\0\5\16\1\0\1\16\1\0\6\17\2\0"
        L"\12\15\2\0\4\16\40\0\1\10\27\0\2\13\6\0"
        L"\12\15\13\0\1\13\1\0\1\13\1\0\1\13\4\0"
        L"\2\13\10\10\1\0\44\10\4\0\24\13\1\0\2\13"
        L"\5\10\13\13\1\0\44\13\11\0\1\13\71\0\53\16"
        L"\24\17\1\16\12\15\6\0\6\16\4\17\4\16\3\17"
        L"\1\16\3\17\2\16\7\17\3\16\4\17\15\16\14\17"
        L"\1\16\1\17\12\15\4\17\2\16\46\10\1\0\1\10"
        L"\5\0\1\10\2\0\53\10\1\0\4\10\u0100\20\111\10"
        L"\1\0\4\10\2\0\7\10\1\0\1\10\1\0\4\10"
        L"\2\0\51\10\1\0\4\10\2\0\41\10\1\0\4\10"
        L"\2\0\7\10\1\0\1\10\1\0\4\10\2\0\17\10"
        L"\1\0\71\10\1\0\4\10\2\0\103\10\2\0\3\13"
        L"\40\0\20\10\20\0\126\10\2\0\6\10\3\0\u016c\10"
        L"\2\0\21\10\1\0\32\10\5\0\113\10\3\0\13\10"
        L"\7\0\15\10\1\0\4\10\3\13\13\0\22\10\3\13"
        L"\13\0\22\10\2\13\14\0\15\10\1\0\3\10\1\0"
        L"\2\13\14\0\64\16\40\17\3\0\1\16\4\0\1\16"
        L"\1\17\2\0\12\15\41\0\4\13\1\0\12\15\6\0"
        L"\131\10\7\0\5\10\2\13\42\10\1\13\1\10\5\0"
        L"\106\10\12\0\37\10\1\0\14\13\4\0\14\13\12\0"
        L"\12\15\36\16\2\0\5\16\13\0\54\16\4\0\32\16"
        L"\6\0\12\15\1\16\3\0\2\16\40\0\27\10\5\13"
        L"\4\0\65\16\12\17\1\0\35\17\2\0\1\13\12\15"
        L"\6\0\12\15\6\0\16\16\2\0\17\13\101\0\5\13"
        L"\57\10\21\13\7\10\4\0\12\15\21\0\11\13\14\0"
        L"\3\13\36\10\15\13\2\10\12\15\54\10\16\13\14\0"
        L"\44\10\24\13\10\0\12\15\3\0\3\10\12\15\44\10"
        L"\2\0\11\10\7\0\53\10\2\0\3\10\20\0\3\13"
        L"\1\0\25\13\4\10\1\13\6\10\1\13\2\10\3\13"
        L"\1\10\5\0\300\10\72\13\1\0\5\13\26\10\2\0"
        L"\6\10\2\0\46\10\2\0\6\10\2\0\10\10\1\0"
        L"\1\10\1\0\1\10\1\0\1\10\1\0\37\10\2\0"
        L"\65\10\1\0\7\10\1\0\1\10\3\0\3\10\1\0"
        L"\7\10\3\0\4\10\2\0\6\10\4\0\15\10\5\0"
        L"\3\10\1\0\7\10\17\0\1\13\1\21\2\13\10\0"
        L"\2\5\12\0\1\5\2\0\1\7\2\0\5\13\1\11"
        L"\14\0\1\12\2\0\2\11\3\0\1\4\4\0\1\12"
        L"\12\0\1\11\13\0\5\13\1\0\12\13\1\0\1\10"
        L"\15\0\1\10\20\0\15\10\63\0\23\13\1\22\15\13"
        L"\21\0\1\10\4\0\1\10\2\0\12\10\1\0\1\10"
        L"\3\0\5\10\4\0\1\12\1\0\1\10\1\0\1\10"
        L"\1\0\1\10\1\0\4\10\1\0\12\10\1\23\2\0"
        L"\4\10\5\0\5\10\4\0\1\10\21\0\51\10\13\0"
        L"\6\12\17\0\2\12\u016f\0\2\12\14\0\1\12\137\0"
        L"\1\12\106\0\1\12\31\0\13\12\4\0\3\12\273\0"
        L"\14\10\1\23\47\10\300\0\2\12\12\0\1\12\11\0"
        L"\1\12\72\0\4\12\1\0\6\12\1\0\14\12\1\0"
        L"\162\12\12\0\166\12\2\0\13\12\1\0\1\12\1\0"
        L"\1\12\6\0\1\12\3\0\1\12\6\0\1\12\12\0"
        L"\2\12\17\0\1\12\2\0\1\12\4\0\1\12\1\0"
        L"\1\12\4\0\3\12\1\0\1\12\13\0\5\12\55\0"
        L"\3\12\11\0\1\12\16\0\1\12\16\0\1\12\164\0"
        L"\2\12\317\0\3\12\23\0\2\12\63\0\1\12\4\0"
        L"\1\12\252\0\57\10\1\0\57\10\1\0\205\10\6\0"
        L"\4\10\3\13\2\10\14\0\46\10\1\0\1\10\5\0"
        L"\1\10\2\0\70\10\7\0\1\10\17\0\1\13\27\10"
        L"\11\0\7\10\1\0\7\10\1\0\7\10\1\0\7\10"
        L"\1\0\7\10\1\0\7\10\1\0\7\10\1\0\7\10"
        L"\1\0\40\13\57\0\1\10\120\0\32\24\1\0\131\24"
        L"\14\0\326\24\57\0\1\10\1\0\1\24\31\0\11\24"
        L"\6\13\1\12\5\25\2\0\3\24\2\10\1\12\3\0"
        L"\126\26\2\0\2\13\2\25\3\26\133\25\1\0\4\25"
        L"\5\0\53\10\1\0\136\20\21\0\33\10\65\0\20\25"
        L"\227\0\1\12\1\0\1\12\66\0\57\25\1\0\130\25"
        L"\250\0\u01b6\24\112\0\360\24\20\0\215\10\103\0\56\10"
        L"\2\0\15\10\3\0\20\10\12\15\2\10\24\0\57\10"
        L"\4\13\1\0\12\13\1\0\37\10\2\13\120\10\2\13"
        L"\45\0\251\10\2\0\5\10\60\0\13\10\1\13\3\10"
        L"\1\13\4\10\1\13\27\10\5\13\30\0\64\10\14\0"
        L"\2\13\62\10\22\13\12\0\12\15\6\0\22\13\6\10"
        L"\3\0\1\10\1\0\2\10\1\13\12\15\34\10\10\13"
        L"\2\0\27\10\15\13\14\0\35\20\3\0\4\13\57\10"
        L"\16\13\16\0\1\10\12\15\6\0\5\16\1\17\12\16"
        L"\12\15\5\16\1\0\51\10\16\13\11\0\3\10\1\13"
        L"\10\10\2\13\2\0\12\15\6\0\33\16\3\17\62\16"
        L"\1\17\1\16\3\17\2\16\2\17\5\16\2\17\1\16"
        L"\1\17\1\16\30\0\5\16\13\10\5\13\2\0\3\10"
        L"\2\13\12\0\6\10\2\0\6\10\2\0\6\10\11\0"
        L"\7\10\1\0\7\10\1\0\70\10\10\0\163\10\10\13"
        L"\1\0\2\13\2\0\12\15\6\0\244\20\14\0\27\20"
        L"\4\0\61\20\4\0\156\24\2\0\152\24\46\0\7\10"
        L"\14\0\5\10\5\0\1\14\1\13\12\14\1\0\15\14"
        L"\1\0\5\14\1\0\1\14\1\0\2\14\1\0\2\14"
        L"\1\0\12\14\142\10\41\0\153\10\22\0\100\10\2\0"
        L"\66\10\50\0\14\10\4\0\16\13\1\27\1\30\1\4"
        L"\2\0\1\7\1\4\13\0\20\13\3\0\2\11\30\0"
        L"\3\11\1\4\1\0\1\5\1\0\1\4\1\7\32\0"
        L"\5\10\1\0\207\10\2\0\1\13\7\0\1\5\4\0"
        L"\1\4\1\0\1\5\1\0\12\15\1\7\1\4\5\0"
        L"\32\10\4\0\1\11\1\0\32\10\13\0\70\25\2\13"
        L"\37\20\3\0\6\20\2\0\6\20\2\0\6\20\2\0"
        L"\3\20\34\0\3\13\4\0\14\10\1\0\32\10\1\0"
        L"\23\10\1\0\2\10\1\0\17\10\2\0\16\10\42\0"
        L"\173\10\105\0\65\10\210\0\1\13\202\0\35\10\3\0"
        L"\61\10\17\0\1\13\37\0\40\10\15\0\36\10\5\0"
        L"\46\10\5\13\5\0\36\10\2\0\44\10\4\0\10\10"
        L"\1\0\5\10\52\0\236\10\2\0\12\15\6\0\44\10"
        L"\4\0\44\10\4\0\50\10\10\0\64\10\234\0\67\10"
        L"\11\0\26\10\12\0\10\10\230\0\6\10\2\0\1\10"
        L"\1\0\54\10\1\0\2\10\3\0\1\10\2\0\27\10"
        L"\12\0\27\10\11\0\37\10\101\0\23\10\1\0\2\10"
        L"\12\0\26\10\12\0\32\10\106\0\70\10\6\0\2\10"
        L"\100\0\1\10\3\13\1\0\2\13\5\0\4\13\4\10"
        L"\1\0\3\10\1\0\35\10\2\0\3\13\4\0\1\13"
        L"\40\0\35\10\3\0\35\10\43\0\10\10\1\0\34\10"
        L"\2\13\31\0\66\10\12\0\26\10\12\0\23\10\15\0"
        L"\22\10\156\0\111\10\67\0\63\10\15\0\63\10\15\0"
        L"\44\10\4\13\10\0\12\15\306\0\35\10\12\0\1\10"
        L"\10\0\26\10\13\13\217\0\27\10\11\0\3\13\65\10"
        L"\17\13\37\0\12\15\17\0\4\13\55\10\13\13\2\0"
        L"\1\13\17\0\1\13\2\0\31\10\7\0\12\15\6\0"
        L"\3\13\44\10\16\13\1\0\12\15\4\0\1\10\2\13"
        L"\11\0\43\10\1\13\2\0\1\10\11\0\3\13\60\10"
        L"\16\13\4\10\4\0\4\13\3\0\12\15\1\10\1\0"
        L"\1\10\43\0\22\10\1\0\31\10\14\13\6\0\1\13"
        L"\101\0\7\10\1\0\1\10\1\0\4\10\1\0\17\10"
        L"\1\0\12\10\7\0\57\10\14\13\5\0\12\15\6\0"
        L"\4\13\1\0\10\10\2\0\2\10\2\0\26\10\1\0"
        L"\7\10\1\0\2\10\1\0\5\10\1\0\2\13\1\10"
        L"\7\13\2\0\2\13\2\0\3\13\2\0\1\10\6\0"
        L"\1\13\5\0\5\10\2\13\2\0\7\13\3\0\5\13"
        L"\213\0\65\10\22\13\4\10\5\0\12\15\4\0\1\13"
        L"\1\10\40\0\60\10\24\13\2\10\1\0\1\10\10\0"
        L"\12\15\246\0\57\10\7\13\2\0\11\13\27\0\4\10"
        L"\2\13\42\0\60\10\21\13\3\0\1\10\13\0\12\15"
        L"\46\0\53\10\15\13\1\10\7\0\12\15\66\0\33\16"
        L"\2\0\17\17\4\0\12\15\2\16\3\0\1\16\300\0"
        L"\54\10\17\13\145\0\100\10\12\15\25\0\1\10\240\0"
        L"\10\10\2\0\47\10\7\13\2\0\7\13\1\10\1\0"
        L"\1\10\1\13\33\0\1\10\12\13\50\10\7\13\1\10"
        L"\4\13\10\0\1\13\10\0\1\10\13\13\56\10\20\13"
        L"\3\0\1\10\42\0\71\10\7\0\11\10\1\0\45\10"
        L"\10\13\1\0\10\13\1\10\17\0\12\15\30\0\36\10"
        L"\2\0\26\13\1\0\16\13\111\0\7\10\1\0\2\10"
        L"\1\0\46\10\6\13\3\0\1\13\1\0\2\13\1\0"
        L"\7\13\1\10\1\13\10\0\12\15\6\0\6\10\1\0"
        L"\2\10\1\0\40\10\5\13\1\0\2\13\1\0\5\13"
        L"\1\10\7\0\12\15\u0136\0\23\10\4\13\11\0\232\10"
        L"\146\0\157\10\21\0\304\10\274\0\57\10\1\0\11\13"
        L"\307\0\107\10\271\0\71\10\7\0\37\10\1\0\12\15"
        L"\146\0\36\10\2\0\5\13\13\0\60\10\7\13\11\0"
        L"\4\10\14\0\12\15\11\0\25\10\5\0\23\10\260\0"
        L"\100\10\200\0\113\10\4\0\1\13\1\10\67\13\7\0"
        L"\4\13\15\10\100\0\2\10\1\0\1\10\34\0\1\25"
        L"\u011e\26\61\0\3\26\21\0\4\25\230\0\153\10\5\0"
        L"\15\10\3\0\11\10\7\0\12\10\3\0\2\13\1\0"
        L"\4\13\301\0\5\13\3\0\26\13\2\0\7\13\36\0"
        L"\4\13\224\0\3\13\273\0\125\10\1\0\107\10\1\0"
        L"\2\10\2\0\1\10\2\0\2\10\2\0\4\10\1\0"
        L"\14\10\1\0\1\10\1\0\7\10\1\0\101\10\1\0"
        L"\4\10\2\0\10\10\1\0\7\10\1\0\34\10\1\0"
        L"\4\10\1\0\5\10\1\0\1\10\3\0\7\10\1\0"
        L"\u0154\10\2\0\31\10\1\0\31\10\1\0\37\10\1\0"
        L"\31\10\1\0\37\10\1\0\31\10\1\0\37\10\1\0"
        L"\31\10\1\0\37\10\1\0\31\10\1\0\10\10\2\0"
        L"\62\15\67\13\4\0\62\13\10\0\1\13\16\0\1\13"
        L"\26\0\5\13\1\0\17\13\120\0\7\13\1\0\21\13"
        L"\2\0\7\13\1\0\2\13\1\0\5\13\325\0\55\10"
        L"\3\0\7\13\7\10\2\0\12\15\4\0\1\10\u0171\0"
        L"\54\10\4\13\12\15\6\0\305\10\13\0\7\13\51\0"
        L"\104\10\7\13\1\10\4\0\12\15\246\0\4\10\1\0"
        L"\33\10\1\0\2\10\1\0\1\10\2\0\1\10\1\0"
        L"\12\10\1\0\4\10\1\0\1\10\1\0\1\10\6\0"
        L"\1\10\4\0\1\10\1\0\1\10\1\0\1\10\1\0"
        L"\3\10\1\0\2\10\1\0\1\10\2\0\1\10\1\0"
        L"\1\10\1\0\1\10\1\0\1\10\1\0\1\10\1\0"
        L"\2\10\1\0\1\10\2\0\4\10\1\0\7\10\1\0"
        L"\4\10\1\0\4\10\1\0\1\10\1\0\12\10\1\0"
        L"\21\10\5\0\3\10\1\0\5\10\1\0\21\10\104\0"
        L"\u0100\12\15\0\3\12\37\0\1\12\32\10\6\0\32\10"
        L"\2\0\4\12\2\23\14\10\2\23\12\10\4\0\1\12"
        L"\2\0\12\12\22\0\71\12\32\31\1\26\17\12\12\0"
        L"\1\12\24\0\1\12\2\0\11\12\1\0\4\12\11\0"
        L"\u01b2\12\5\32\u013e\12\10\0\u010a\12\60\0\200\12\164\0"
        L"\14\12\125\0\53\12\14\0\4\12\70\0\10\12\12\0"
        L"\6\12\50\0\10\12\36\0\122\12\14\0\57\12\1\0"
        L"\12\12\1\0\u03b7\12\2\0\327\24\51\0\65\24\13\0"
        L"\336\24\2\0\u0182\24\16\0\u0131\24\37\0\36\24\343\0"
        L"\1\13\36\0\137\33\1\34\200\0\360\13\20\0";

template <class T>
std::vector<int32_t> StandardTokenizerImpl<T>::zzUnpackcmap_blocks() {
    std::vector<int32_t> result(35328);
    int32_t offset = 0;
    offset = zzUnpackcmap_blocks(ZZ_CMAP_BLOCKS_PACKED_0, offset, result);
    return result;
}

template <class T>
int32_t StandardTokenizerImpl<T>::zzUnpackcmap_blocks(const wchar_t* packed, int32_t offset,
                                                      std::vector<int32_t>& result) {
    int32_t i = 0;
    int32_t j = offset;
    while (i < 3838) {
        int32_t count = packed[i++];
        int32_t value = packed[i++];
        do {
            result[j++] = value;
        } while (--count > 0);
    }
    return j;
}

template <class T>
const std::vector<int32_t> StandardTokenizerImpl<T>::ZZ_ACTION = zzUnpackAction();
template <class T>
const wchar_t StandardTokenizerImpl<T>::ZZ_ACTION_PACKED_0[] =
        L"\1\0\2\1\1\2\1\3\1\1\1\4\1\3\1\2"
        L"\1\5\1\6\1\1\1\4\1\7\1\10\1\11\1\1"
        L"\1\4\1\0\1\4\2\0\1\2\1\4\1\2\1\0"
        L"\2\3\1\0\1\3\2\4\1\0\1\3\1\0\2\4"
        L"\1\0\4\4\1\0\1\4\2\0\1\4\2\3\2\4"
        L"\1\0\3\4\1\3\3\4";

template <class T>
std::vector<int32_t> StandardTokenizerImpl<T>::zzUnpackAction() {
    std::vector<int32_t> result(59);
    int32_t offset = 0;
    offset = zzUnpackAction(ZZ_ACTION_PACKED_0, offset, result);
    return result;
}

template <class T>
int32_t StandardTokenizerImpl<T>::zzUnpackAction(const wchar_t* packed, int32_t offset,
                                                 std::vector<int32_t>& result) {
    int32_t i = 0;
    int32_t j = offset;
    while (i < 88) {
        int32_t count = packed[i++];
        int32_t value = packed[i++];
        do {
            result[j++] = value;
        } while (--count > 0);
    }
    return j;
}

template <class T>
const std::vector<int32_t> StandardTokenizerImpl<T>::ZZ_ROWMAP = zzUnpackRowMap();
template <class T>
const wchar_t StandardTokenizerImpl<T>::ZZ_ROWMAP_PACKED_0[] =
        L"\0\0\0\35\0\72\0\127\0\164\0\221\0\256\0\313\0\350\0\u0105\0\u0122\0"
        L"\u013f\0\u015c\0\u0179\0\u0196\0\u01b3\0\u01d0\0\u01ed\0\72\0\u020a\0"
        L"\u0227\0\u0244\0\u0261\0\u027e\0\u029b\0\u02b8\0\u02d5\0\u02f2\0\221"
        L"\0\u030f\0\u032c\0\u0349\0\u0366\0\u0383\0\u013f\0\u03a0\0\u03bd\0"
        L"\u01d0\0\u03da\0\u03f7\0\u0414\0\u0431\0\u044e\0\u046b\0\u0488\0"
        L"\u04a5\0\u04c2\0\u04df\0\u04fc\0\u0519\0\u0536\0\u0553\0\35\0\u0570\0"
        L"\u058d\0\u05aa\0\u05c7\0\164\0\u05e4";

template <class T>
std::vector<int32_t> StandardTokenizerImpl<T>::zzUnpackRowMap() {
    std::vector<int32_t> result(59);
    int32_t offset = 0;
    offset = zzUnpackRowMap(ZZ_ROWMAP_PACKED_0, offset, result);
    return result;
}

template <class T>
int32_t StandardTokenizerImpl<T>::zzUnpackRowMap(const wchar_t* packed, int32_t offset,
                                                 std::vector<int32_t>& result) {
    int32_t i = 0;
    int32_t j = offset;
    while (i < 118) {
        int32_t high = packed[i++] << 16;
        result[j++] = high | packed[i++];
    }
    return j;
}

template <class T>
const std::vector<int32_t> StandardTokenizerImpl<T>::ZZ_TRANS = zzUnpackTrans();
template <class T>
const wchar_t StandardTokenizerImpl<T>::ZZ_TRANS_PACKED_0[] =
        L"\2\2\1\3\3\2\1\4\1\2\1\5\1\6\1\7"
        L"\1\2\1\10\1\11\2\12\1\13\1\14\1\2\1\15"
        L"\1\16\1\17\1\20\2\2\1\21\1\22\2\2\50\0"
        L"\1\23\3\0\1\23\1\0\1\23\1\24\5\0\1\25"
        L"\1\0\3\23\3\0\3\26\1\11\1\0\1\5\1\27"
        L"\1\0\1\4\1\10\1\11\1\0\1\4\1\5\1\4"
        L"\1\30\1\5\3\0\1\11\1\31\1\0\3\4\3\0"
        L"\1\32\1\0\1\32\1\33\1\32\1\5\1\34\1\0"
        L"\1\5\1\10\1\33\1\0\5\5\3\0\2\5\1\0"
        L"\3\5\6\0\1\11\1\0\1\5\1\35\1\0\1\35"
        L"\1\10\1\11\1\0\1\35\1\5\2\35\1\5\1\0"
        L"\1\36\1\0\2\35\1\0\3\35\13\0\1\7\3\0"
        L"\1\7\1\0\1\37\1\7\5\0\1\40\1\0\3\7"
        L"\1\0\1\41\1\0\1\42\1\0\1\32\1\33\1\32"
        L"\1\5\1\34\1\0\2\10\1\33\1\0\1\10\1\5"
        L"\2\10\1\5\3\0\2\10\1\0\3\10\3\0\3\26"
        L"\1\11\1\0\1\5\1\27\1\0\1\11\1\10\1\11"
        L"\1\0\1\11\1\5\2\11\1\5\3\0\2\11\1\0"
        L"\3\11\13\0\1\12\2\0\2\12\1\0\2\12\4\0"
        L"\2\12\1\0\3\12\3\0\1\32\1\0\1\32\1\33"
        L"\1\32\1\5\1\34\1\0\1\13\1\10\1\33\1\0"
        L"\4\13\1\5\3\0\2\13\1\0\3\13\12\0\1\7"
        L"\6\0\1\43\1\0\1\7\14\0\1\32\1\0\1\32"
        L"\1\33\1\32\1\5\1\34\1\0\1\15\1\10\1\33"
        L"\1\0\1\15\1\5\1\44\1\15\1\5\3\0\1\5"
        L"\1\45\1\0\3\15\13\0\1\16\3\0\1\16\1\0"
        L"\2\16\4\0\2\16\1\0\3\16\11\0\1\34\1\0"
        L"\1\17\3\0\1\17\1\0\2\17\2\0\1\17\1\0"
        L"\2\17\1\0\3\17\13\0\1\20\3\0\1\20\1\0"
        L"\2\20\4\0\2\20\1\0\3\20\13\0\1\46\3\0"
        L"\1\46\1\0\2\46\4\0\2\46\1\47\3\46\13\0"
        L"\1\22\3\0\1\22\1\0\1\50\1\22\7\0\3\22"
        L"\13\0\1\24\3\0\1\24\1\0\2\24\5\0\1\25"
        L"\1\0\3\24\22\0\1\51\20\0\1\11\4\0\1\26"
        L"\1\0\1\11\1\0\1\26\1\0\2\26\4\0\2\26"
        L"\1\0\3\26\6\0\1\11\1\0\1\5\1\27\1\0"
        L"\1\27\1\10\1\11\1\0\1\27\1\5\2\27\1\5"
        L"\1\0\1\36\1\0\2\27\1\0\3\27\3\0\3\26"
        L"\1\11\1\0\1\5\1\27\1\0\1\30\1\10\1\11"
        L"\1\0\1\30\1\5\2\30\1\5\3\0\1\11\1\31"
        L"\1\0\3\30\3\0\3\26\1\11\1\0\1\5\1\27"
        L"\1\0\1\11\1\10\1\11\1\0\1\11\1\5\1\11"
        L"\1\52\1\5\3\0\2\11\1\0\3\11\10\0\1\5"
        L"\2\0\1\32\1\5\2\0\1\32\1\5\2\32\1\5"
        L"\3\0\2\32\1\0\3\32\3\0\3\53\1\33\1\0"
        L"\1\5\1\34\1\0\1\33\1\10\1\33\1\0\1\33"
        L"\1\5\2\33\1\5\3\0\2\33\1\0\3\33\6\0"
        L"\1\33\1\0\1\5\1\34\1\0\1\34\1\10\1\33"
        L"\1\0\1\34\1\5\2\34\1\5\1\0\1\36\1\0"
        L"\2\34\1\0\3\34\11\0\1\34\1\0\1\36\3\0"
        L"\1\36\1\0\2\36\2\0\1\36\1\0\2\36\1\0"
        L"\3\36\12\0\1\54\1\7\3\0\1\7\1\0\1\37"
        L"\1\7\1\54\4\0\1\40\1\0\3\7\21\0\1\55"
        L"\11\0\1\56\14\0\1\41\1\42\2\0\1\41\1\0"
        L"\2\41\4\0\2\41\1\0\3\41\6\0\1\33\1\0"
        L"\1\5\1\34\1\0\1\42\1\10\1\33\1\0\1\42"
        L"\1\5\2\42\1\5\3\0\2\42\1\0\3\42\3\0"
        L"\1\32\1\0\1\32\1\33\1\32\1\5\1\34\1\54"
        L"\1\15\1\10\1\33\1\0\1\15\1\5\1\44\1\15"
        L"\1\57\3\0\1\5\1\45\1\0\3\15\3\0\1\32"
        L"\1\0\1\32\1\33\1\32\1\5\1\34\1\0\1\5"
        L"\1\10\1\33\1\0\2\5\1\60\2\5\3\0\2\5"
        L"\1\0\1\5\1\61\1\5\13\0\1\47\3\0\1\47"
        L"\1\0\2\47\4\0\2\47\1\0\3\47\12\0\1\54"
        L"\1\22\3\0\1\22\1\0\1\50\1\22\1\54\6\0"
        L"\3\22\13\0\1\51\3\0\1\51\1\0\2\51\7\0"
        L"\3\51\3\0\3\26\1\11\1\0\1\5\1\27\1\0"
        L"\1\52\1\10\1\11\1\0\1\52\1\5\2\52\1\5"
        L"\3\0\2\11\1\0\3\52\6\0\1\33\4\0\1\53"
        L"\1\0\1\33\1\0\1\53\1\0\2\53\4\0\2\53"
        L"\1\0\3\53\13\0\1\54\3\0\1\54\1\0\1\62"
        L"\1\54\5\0\1\63\1\0\3\54\12\0\1\54\6\0"
        L"\1\64\1\0\1\54\6\0\1\22\35\0\1\56\1\65"
        L"\3\0\1\32\1\0\1\32\1\33\1\32\1\5\1\34"
        L"\1\0\1\57\1\10\1\33\1\0\1\57\1\5\1\66"
        L"\1\57\1\5\3\0\1\5\1\67\1\0\3\57\3\0"
        L"\1\32\1\0\1\32\1\33\1\32\1\5\1\34\1\54"
        L"\1\5\1\10\1\33\1\0\2\5\1\70\1\5\1\57"
        L"\3\0\2\5\1\0\1\71\2\5\3\0\1\32\1\0"
        L"\1\32\1\33\1\32\1\5\1\34\1\0\1\5\1\10"
        L"\1\33\1\0\5\5\3\0\2\5\1\0\1\5\1\61"
        L"\1\72\12\0\2\54\3\0\1\54\1\0\1\62\2\54"
        L"\4\0\1\63\1\0\3\54\21\0\1\55\25\0\1\54"
        L"\6\0\1\64\1\0\1\54\14\0\1\32\1\0\1\32"
        L"\1\33\1\32\1\5\1\34\1\54\1\57\1\10\1\33"
        L"\1\0\1\57\1\5\1\66\2\57\3\0\1\5\1\67"
        L"\1\0\3\57\3\0\1\32\1\0\1\32\1\33\1\32"
        L"\1\5\1\34\1\0\1\5\1\10\1\33\1\0\2\5"
        L"\1\60\2\5\3\0\2\5\1\0\3\5\3\0\1\32"
        L"\1\0\1\32\1\33\1\32\1\5\1\34\1\54\1\5"
        L"\1\10\1\33\1\0\2\5\1\70\1\5\1\57\3\0"
        L"\2\5\1\0\3\5\3\0\1\32\1\0\1\32\1\33"
        L"\1\32\1\5\1\34\1\0\1\71\1\10\1\33\1\0"
        L"\1\71\1\5\1\73\1\71\1\5\3\0\2\5\1\0"
        L"\3\71\3\0\1\32\1\0\1\32\1\33\1\32\1\5"
        L"\1\34\1\54\1\71\1\10\1\33\1\0\1\71\1\5"
        L"\1\73\1\71\1\57\3\0\2\5\1\0\3\71";

template <class T>
std::vector<int32_t> StandardTokenizerImpl<T>::zzUnpackTrans() {
    std::vector<int32_t> result(1537);
    int32_t offset = 0;
    offset = zzUnpackTrans(ZZ_TRANS_PACKED_0, offset, result);
    return result;
}

template <class T>
int32_t StandardTokenizerImpl<T>::zzUnpackTrans(const wchar_t* packed, int32_t offset,
                                                std::vector<int32_t>& result) {
    int32_t i = 0;
    int32_t j = offset;
    while (i < 1550) {
        int32_t count = packed[i++];
        int32_t value = packed[i++];
        value--;
        do {
            result[j++] = value;
        } while (--count > 0);
    }
    return j;
}

template <class T>
const std::vector<std::string> StandardTokenizerImpl<T>::ZZ_ERROR_MSG = {
        "Unknown internal scanner error", "Error: could not match input",
        "Error: pushback value was too large"};

template <class T>
const std::vector<int32_t> StandardTokenizerImpl<T>::ZZ_ATTRIBUTE = zzUnpackAttribute();
template <class T>
const wchar_t StandardTokenizerImpl<T>::ZZ_ATTRIBUTE_PACKED_0[] =
        L"\1\0\1\11\20\1\1\0\1\1\2\0\3\1\1\0"
        L"\2\1\1\0\3\1\1\0\1\1\1\0\2\1\1\0"
        L"\4\1\1\0\1\1\2\0\5\1\1\0\1\11\6\1";

template <class T>
std::vector<int32_t> StandardTokenizerImpl<T>::zzUnpackAttribute() {
    std::vector<int32_t> result(59);
    int32_t offset = 0;
    offset = zzUnpackAttribute(ZZ_ATTRIBUTE_PACKED_0, offset, result);
    return result;
}

template <class T>
int32_t StandardTokenizerImpl<T>::zzUnpackAttribute(const wchar_t* packed, int32_t offset,
                                                    std::vector<int32_t>& result) {
    int32_t i = 0;
    int32_t j = offset;
    while (i < 48) {
        int32_t count = packed[i++];
        int32_t value = packed[i++];
        do {
            result[j++] = value;
        } while (--count > 0);
    }
    return j;
}

template <class T>
StandardTokenizerImpl<T>::StandardTokenizerImpl(CL_NS(util)::Reader* reader)
        : zzBuffer(ZZ_BUFFERSIZE), zzReader(reader) {}

template <>
bool StandardTokenizerImpl<char>::zzRefill() {
    if (zzStartRead > 0) {
        zzEndRead += zzFinalHighSurrogate;
        zzFinalHighSurrogate = 0;
        std::copy_n(zzBuffer.begin() + zzStartRead, zzEndRead - zzStartRead, zzBuffer.begin());
        zzEndRead -= zzStartRead;
        zzCurrentPos -= zzStartRead;
        zzMarkedPos -= zzStartRead;
        zzStartRead = 0;
    }

    int32_t requested = zzBuffer.size() - zzEndRead - zzFinalHighSurrogate;
    if (requested == 0) {
        return true;
    }
    int32_t numRead = zzReader->readCopy(zzBuffer.data(), zzEndRead, requested);

    if (numRead == 0) {
        _CLTHROWA(CL_ERR_IO,
                  "Reader returned 0 characters. See JFlex examples/zero-reader for a workaround.");
    }
    if (numRead > 0) {
        zzEndRead += numRead;

        int32_t i = 1;
        for (; i <= 4; i++) {
            uint8_t ch = zzBuffer[zzEndRead - i];
            if ((ch & 0xC0) != 0x80) {
                break;
            }
        }

        int32_t len = Character::utf8Length(zzBuffer[zzEndRead - i]);
        if (i != len) {
            if (numRead == requested) {
                zzEndRead -= i;
                zzFinalHighSurrogate = i;
            } else {
                int32_t c = zzReader->read();
                if (c == -1) {
                    return true;
                } else {
                    _CLTHROWA(CL_ERR_IllegalArgument, "Why did you come here");
                }
            }
        }

        return false;
    }

    return true;
}

template <>
bool StandardTokenizerImpl<wchar_t>::zzRefill() {
    if (zzStartRead > 0) {
        zzEndRead += zzFinalHighSurrogate;
        zzFinalHighSurrogate = 0;
        std::copy_n(zzBuffer.begin() + zzStartRead, zzEndRead - zzStartRead, zzBuffer.begin());
        zzEndRead -= zzStartRead;
        zzCurrentPos -= zzStartRead;
        zzMarkedPos -= zzStartRead;
        zzStartRead = 0;
    }

    int32_t requested = zzBuffer.size() - zzEndRead - zzFinalHighSurrogate;
    if (requested == 0) {
        return true;
    }
    int32_t numRead = zzReader->readCopy(zzBuffer.data(), zzEndRead, requested);

    if (numRead == 0) {
        _CLTHROWA(CL_ERR_IO,
                  "Reader returned 0 characters. See JFlex examples/zero-reader for a workaround.");
    }
    if (numRead > 0) {
        zzEndRead += numRead;
        if (Character::isHighSurrogate(zzBuffer[zzEndRead - 1])) {
            if (numRead == requested) {
                --zzEndRead;
                zzFinalHighSurrogate = 1;
                if (numRead == 1) {
                    return true;
                }
            } else {
                int32_t c = zzReader->read();
                if (c == -1) {
                    return true;
                } else {
                    zzBuffer[zzEndRead++] = static_cast<wchar_t>(c);
                }
            }
        }
        return false;
    }

    return true;
}

template <class T>
void StandardTokenizerImpl<T>::yyclose() {
    zzAtEOF = true;
    zzEndRead = zzStartRead;

    // if (zzReader != nullptr) {
    //     zzReader->close();
    // }
}

template <class T>
void StandardTokenizerImpl<T>::yyreset(CL_NS(util)::Reader* reader) {
    zzReader = reader;
    zzEOFDone = false;
    yyResetPosition();
    zzLexicalState = YYINITIAL;
}

template <class T>
void StandardTokenizerImpl<T>::yyResetPosition() {
    zzAtBOL = true;
    zzAtEOF = false;
    zzCurrentPos = 0;
    zzMarkedPos = 0;
    zzStartRead = 0;
    zzEndRead = 0;
    zzFinalHighSurrogate = 0;
    yyline = 0;
    yycolumn = 0;
    yychar_Conflict = 0LL;
}

template <class T>
void StandardTokenizerImpl<T>::zzScanError(int32_t errorCode) {
    std::string message;
    try {
        message = ZZ_ERROR_MSG[errorCode];
    } catch (const std::out_of_range& e) {
        message = ZZ_ERROR_MSG[ZZ_UNKNOWN_ERROR];
    }
    _CLTHROWA(CL_ERR_Runtime, message.c_str());
}

template <class T>
int32_t StandardTokenizerImpl<T>::getNextToken() {
    int32_t zzInput;
    int32_t zzAction;

    int32_t zzCurrentPosL;
    int32_t zzMarkedPosL;
    int32_t zzEndReadL = zzEndRead;
    std::vector<T>& zzBufferL = zzBuffer;

    const std::vector<int32_t>& zzTransL = ZZ_TRANS;
    const std::vector<int32_t>& zzRowMapL = ZZ_ROWMAP;
    const std::vector<int32_t>& zzAttrL = ZZ_ATTRIBUTE;

    while (true) {
        zzMarkedPosL = zzMarkedPos;

        yychar_Conflict += zzMarkedPosL - zzStartRead;

        zzAction = -1;

        zzCurrentPosL = zzCurrentPos = zzStartRead = zzMarkedPosL;

        zzState = ZZ_LEXSTATE[zzLexicalState];

        int32_t zzAttributes = zzAttrL[zzState];
        if ((zzAttributes & 1) == 1) {
            zzAction = zzState;
        }

        {
            while (true) {
                if (zzCurrentPosL < zzEndReadL) {
                    if constexpr (std::is_same_v<T, wchar_t>) {
                        zzInput = Character::codePointAt(zzBufferL.data(), ZZ_BUFFERSIZE, zzCurrentPosL,
                                                         zzEndReadL);
                        zzCurrentPosL += Character::charCount(zzInput);
                    } else {
                        int32_t len = Character::utf8Length(zzBufferL[zzCurrentPosL]);
                        zzInput = Character::decodeCodepoint(
                                (const uint8_t*)&zzBufferL[zzCurrentPosL], len);
                        zzCurrentPosL += len;
                    }
                } else if (zzAtEOF) {
                    zzInput = YYEOF;
                    goto zzForActionBreak;
                } else {
                    zzCurrentPos = zzCurrentPosL;
                    zzMarkedPos = zzMarkedPosL;
                    bool eof = zzRefill();
                    zzCurrentPosL = zzCurrentPos;
                    zzMarkedPosL = zzMarkedPos;
                    zzBufferL = zzBuffer;
                    zzEndReadL = zzEndRead;
                    if (eof) {
                        zzInput = YYEOF;
                        goto zzForActionBreak;
                    } else {
                        if constexpr (std::is_same_v<T, wchar_t>) {
                            zzInput = Character::codePointAt(zzBuffer.data(), ZZ_BUFFERSIZE,
                                                             zzCurrentPosL, zzEndReadL);
                            zzCurrentPosL += Character::charCount(zzInput);
                        } else {
                            int32_t len = Character::utf8Length(zzBufferL[zzCurrentPosL]);
                            zzInput = Character::decodeCodepoint(
                                    (const uint8_t*)&zzBufferL[zzCurrentPosL], len);
                            zzCurrentPosL += len;
                        }
                    }
                }
                int32_t zzNext = zzTransL[zzRowMapL[zzState] + zzCMap(zzInput)];
                if (zzNext == -1) {
                    goto zzForActionBreak;
                }
                zzState = zzNext;

                zzAttributes = zzAttrL[zzState];
                if ((zzAttributes & 1) == 1) {
                    zzAction = zzState;
                    zzMarkedPosL = zzCurrentPosL;
                    if ((zzAttributes & 8) == 8) {
                        goto zzForActionBreak;
                    }
                }
            }
        }
    zzForActionBreak:

        zzMarkedPos = zzMarkedPosL;

        if (zzInput == YYEOF && zzStartRead == zzCurrentPos) {
            zzAtEOF = true;
            { return YYEOF; }
        } else {
            switch (zzAction < 0 ? zzAction : ZZ_ACTION[zzAction]) {
            case 1: {
                break;
            }
                // fall through
            case 10:
                break;
            case 2: {
                return NUMERIC_TYPE;
            }
                // fall through
            case 11:
                break;
            case 3: {
                return WORD_TYPE;
            }
                // fall through
            case 12:
                break;
            case 4: {
                return EMOJI_TYPE;
            }
                // fall through
            case 13:
                break;
            case 5: {
                return SOUTH_EAST_ASIAN_TYPE;
            }
                // fall through
            case 14:
                break;
            case 6: {
                return HANGUL_TYPE;
            }
                // fall through
            case 15:
                break;
            case 7: {
                return IDEOGRAPHIC_TYPE;
            }
                // fall through
            case 16:
                break;
            case 8: {
                return KATAKANA_TYPE;
            }
                // fall through
            case 17:
                break;
            case 9: {
                return HIRAGANA_TYPE;
            }
                // fall through
            case 18:
                break;
            default:
                zzScanError(ZZ_NO_MATCH);
            }
        }
    }
}

template class StandardTokenizerImpl<char>;
template class StandardTokenizerImpl<wchar_t>;

CL_NS_END2
