/**
 * @file    AesECB192.h
 * @brief   Definition of Aes ECB 192 bits algorithm.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_AESECB192_H
#define RED_AESECB192_H

#include <string>

namespace Red {
    /**
     * @brief EncryptAesECB192
     *
     * @param in    String to encrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Encrypted string
     */
    std::string * EncryptAesECB192(const std::string& in, const std::string_view key);

    /**
     * @brief EncryptAesECB192
     *
     * @param in    String to decrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Decrypted string
     */
    std::string * DecryptAesECB192(const std::string& in, const std::string_view key);
}

#endif // RED_AESECB192_H
