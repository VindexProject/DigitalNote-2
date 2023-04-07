/**
 * Utilities for converting data from/to strings.
 */
#ifndef UTILSTRENCODINGS_H
#define UTILSTRENCODINGS_H

#include <stdint.h>
#include <string>
#include <vector>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <openssl/crypto.h> // for OPENSSL_cleanse()
#include <openssl/rand.h>
#include <openssl/bn.h>

#define BEGIN(a)			((char*)&(a))
#define END(a)				((char*)&((&(a))[1]))
#define UBEGIN(a)			((unsigned char*)&(a))
#define UEND(a)				((unsigned char*)&((&(a))[1]))
#define ARRAYLEN(array)		(sizeof(array)/sizeof((array)[0]))

extern const signed char p_util_hexdigit[256];

signed char HexDigit(char c);

std::vector<unsigned char> DecodeBase64(const char* p, bool* pfInvalid = NULL);
std::string DecodeBase64(const std::string& str);
std::string EncodeBase64(const unsigned char* pch, size_t len);
std::string EncodeBase64(const std::string& str);
SecureString DecodeBase64Secure(const SecureString& input);
SecureString EncodeBase64Secure(const SecureString& input);
std::vector<unsigned char> DecodeBase32(const char* p, bool* pfInvalid = NULL);
std::string DecodeBase32(const std::string& str);
std::string EncodeBase32(const unsigned char* pch, size_t len);
std::string EncodeBase32(const std::string& str);


std::string i64tostr(int64_t n);
std::string itostr(int n);
int64_t atoi64(const char* psz);
int64_t atoi64(const std::string& str);
int atoi(const std::string& str);

/**
 * Convert string to signed 32-bit integer with strict parse error feedback.
 * @returns true if the entire string could be parsed as valid integer,
 *   false if not the entire string could be parsed or when overflow or underflow occurred.
 */
bool ParseInt32(const std::string& str, int32_t *out);

template<typename T>
std::string HexStr(const T itbegin, const T itend, bool fSpaces=false)
{
    std::string rv;
    static const char hexmap[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
                                     '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    rv.reserve((itend-itbegin)*3);
    for(T it = itbegin; it < itend; ++it)
    {
        unsigned char val = (unsigned char)(*it);
        if(fSpaces && it != itbegin)
            rv.push_back(' ');
        rv.push_back(hexmap[val>>4]);
        rv.push_back(hexmap[val&15]);
    }

    return rv;
}

template<typename T>
inline std::string HexStr(const T& vch, bool fSpaces=false)
{
    return HexStr(vch.begin(), vch.end(), fSpaces);
}

/** 
 * Format a paragraph of text to a fixed width, adding spaces for
 * indentation to any added line.
 */
std::string FormatParagraph(const std::string &in, size_t width=79, size_t indent=0);

#endif // UTILSTRENCODINGS_H
