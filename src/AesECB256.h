/**
 * @file    AesECB256.h
 * @brief   Definition of Aes ECB 256 bits algorithm.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_AESECB256_H
#define RED_AESECB256_H

#include <string>

namespace Red {
    /**
     * @brief EncryptAesECB256
     *
     * @param in    String to encrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Encrypted string
     */
    std::string * EncryptAesECB256(const std::string& in, const std::string_view key);

    /**
     * @brief EncryptAesECB256
     *
     * @param in    String to decrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Decrypted string
     */
    std::string * DecryptAesECB256(const std::string& in, const std::string_view key);
}

#endif // RED_AESECB256_H
