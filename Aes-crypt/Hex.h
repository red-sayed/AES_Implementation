/**
 * @file    Hex.h
 * @brief   Hex is a lib, which has functions converts string to a string with hex values.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_HEX_H
#define RED_HEX_H

#include <string>

#define REDHEX_VERSION            "1.0"

namespace Red {
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

            const unsigned char ch = (const unsigned char) a[i];

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
}

#endif // RED_HEX_H
