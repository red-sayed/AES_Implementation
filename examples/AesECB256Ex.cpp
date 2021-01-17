#include <iostream>
#include <string>

#include "AesECB256.h"

/**
 * @brief GetHexArray
 *
 * @param a String to get hex string from.
 *
 * @return String with hex result.
 */
inline std::string GetHexArray(const std::string_view a) {
    std::string  Result = "";

    for (unsigned long long int i = 0; i < a.length(); i++) {
        char const hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b','c','d','e','f'};

        const unsigned char ch = a[i];
        Result.append(&hex[(ch  & 0xF0) >> 4], 1);
        Result.append(&hex[ch & 0xF], 1);
    }

    return Result;
}

/**
 * @brief GetStrArray
 *
 * @param a Hex string to get string from.
 *
 * @return Normal string.
 */
inline std::string GetStrArray(const std::string_view a) {
    std::string Result = "";

    for (unsigned long long int n = 0; n < a.length(); n += 2) {
        std::string HexByte = "";

        HexByte += a[n];
        HexByte += a[n + 1];

        int num = std::stoi(HexByte, nullptr, 16);

        Result.push_back((char) num);
    }

    return Result;
}

int main() {
    // Key length is 32.
    std::string key = "0123456789abcdef1234567812345678";
    std::string in  = "0123456789abcdef";

    std::string EncryptedStr = Red::EncryptAesECB256(in, key);
    std::string EncryptedHex = GetHexArray(EncryptedStr);

    std::cout << "Encrypted(hex): '" << EncryptedHex << "'." << std::endl;

    std::string ForDecrypt = GetStrArray(EncryptedHex);
    std::string Decrypted  = Red::DecryptAesECB256(ForDecrypt, key);

    std::cout << "Decrypted(str): '" << Decrypted << "'." << std::endl;

    return 0;
}