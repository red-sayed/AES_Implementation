/**
 * @file    AesECB192.cpp
 * @brief   Definition of Aes ECB 192 bits algorithm.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "AesECB192.h"
#include "_private/AesDeclarations.h"

using namespace Red::Aes;

// Base definitions.
#define AES_256 0
#define Nk      6
#define Nr      12
#define KEY_EXP_SIZE 208

// Object for encryption/decryption.
struct AES_ctx_ECB_192 {
    uint8_t RoundKey[KEY_EXP_SIZE];
};

inline static void KeyExpansion(uint8_t *RoundKey, const uint8_t *Key) {
    unsigned i, j, k;
    uint8_t tempa[4];

    for (i = 0; i < Nk; ++i) {
        RoundKey[(i * 4) + 0] = Key[(i * 4) + 0];
        RoundKey[(i * 4) + 1] = Key[(i * 4) + 1];
        RoundKey[(i * 4) + 2] = Key[(i * 4) + 2];
        RoundKey[(i * 4) + 3] = Key[(i * 4) + 3];
    }

    for (i = Nk; i < Nb * (Nr + 1); ++i) {
        {
            k = (i - 1) * 4;
            tempa[0]=RoundKey[k + 0];
            tempa[1]=RoundKey[k + 1];
            tempa[2]=RoundKey[k + 2];
            tempa[3]=RoundKey[k + 3];
        }

        if (i % Nk == 0) {
            {
                const uint8_t u8tmp = tempa[0];
                tempa[0] = tempa[1];
                tempa[1] = tempa[2];
                tempa[2] = tempa[3];
                tempa[3] = u8tmp;
            }

            {
                tempa[0] = getSBoxValue(tempa[0]);
                tempa[1] = getSBoxValue(tempa[1]);
                tempa[2] = getSBoxValue(tempa[2]);
                tempa[3] = getSBoxValue(tempa[3]);
            }

            tempa[0] = tempa[0] ^ Rcon[i/Nk];
        }

        #if AES_256 == 1
        if (i % Nk == 4) {
            {
                tempa[0] = getSBoxValue(tempa[0]);
                tempa[1] = getSBoxValue(tempa[1]);
                tempa[2] = getSBoxValue(tempa[2]);
                tempa[3] = getSBoxValue(tempa[3]);
            }
        }
        #endif

        j = i * 4; k=(i - Nk) * 4;
        RoundKey[j + 0] = RoundKey[k + 0] ^ tempa[0];
        RoundKey[j + 1] = RoundKey[k + 1] ^ tempa[1];
        RoundKey[j + 2] = RoundKey[k + 2] ^ tempa[2];
        RoundKey[j + 3] = RoundKey[k + 3] ^ tempa[3];
    }
}

// Key expansion operation.
inline static void AES_init_ctx(struct AES_ctx_ECB_192 *ctx, const uint8_t *key) {
    KeyExpansion(ctx->RoundKey, key);
}

inline static void Cipher(state_t *state, const uint8_t *RoundKey) {
    uint8_t round = 0;

    AddRoundKey(0, state, RoundKey);

    for (round = 1; ; ++round) {
        SubBytes(state);
        ShiftRows(state);

        if (round == Nr) {
            break;
        }

        MixColumns(state);
        AddRoundKey(round, state, RoundKey);
    }

    AddRoundKey(Nr, state, RoundKey);
}

inline static void InvCipher(state_t *state, const uint8_t *RoundKey) {
    uint8_t round = 0;

    AddRoundKey(Nr, state, RoundKey);

    for (round = (Nr - 1); ; --round) {
        InvShiftRows(state);
        InvSubBytes(state);
        AddRoundKey(round, state, RoundKey);

        if (round == 0) {
            break;
        }

        InvMixColumns(state);
    }
}

// Encrypt operation.
inline static void AES_ECB_encrypt(const struct AES_ctx_ECB_192 *ctx, uint8_t *buf) {
    Cipher((state_t *) buf, ctx->RoundKey);
}

// Decrypt operation.
inline static void AES_ECB_decrypt(const struct AES_ctx_ECB_192 *ctx, uint8_t *buf) {
    InvCipher((state_t *) buf, ctx->RoundKey);
}

/**
 * @brief Red::EncryptAesECB192
 *
 * @param in    String to encrypt
 * @param key   Private key
 * @param iv    Initialization vector
 *
 * @return Encrypted string
 */
const std::string Red::EncryptAesECB192(const std::string& in, const std::string_view key) {
    std::string Encrypted = "";

    unsigned long long int InLen = in.length();

    // Getting num of blocks.
    unsigned long long int NumOfBlocks = 1;

    if (InLen > BLOCK_BYTES_LENGTH) {
        NumOfBlocks = InLen / BLOCK_BYTES_LENGTH;

        if (InLen % BLOCK_BYTES_LENGTH != 0) {
            NumOfBlocks++;
        }
    }

    // Block operations.
    for (unsigned long long int CurrentBlock = 1; CurrentBlock <= NumOfBlocks; CurrentBlock++) {
        std::string Block = "";

        // Getting a block of information.
        for (unsigned long long int g = 0; g < BLOCK_BYTES_LENGTH; g++) {
            Block.push_back(in[BLOCK_BYTES_LENGTH * (CurrentBlock - 1) + g]);
        }

        // Padding.
        if (Block.length() != BLOCK_BYTES_LENGTH) {
            PaddingNulls(Block, Block.length(), BLOCK_BYTES_LENGTH);
        }

        // Encrypting.
        AES_ctx_ECB_192 ctx;

        AES_init_ctx(&ctx, (const uint8_t *) key.data());
        AES_ECB_encrypt(&ctx, (uint8_t *) Block.data());

        Encrypted.append(Block);
    }

    return Encrypted;
}

/**
 * @brief Red::DecryptAesECB192
 *
 * @param in    String to decrypt
 * @param key   Private key
 * @param iv    Initialization vector
 *
 * @return Decrypted string
 */
const std::string Red::DecryptAesECB192(const std::string& in, const std::string_view key) {
    std::string Decrypted = "";

    unsigned long long int InLen = in.length();

    // Getting num of blocks.
    unsigned long long int NumOfBlocks = 1;

    if (InLen > BLOCK_BYTES_LENGTH) {
        NumOfBlocks = InLen / BLOCK_BYTES_LENGTH;

        if (InLen % BLOCK_BYTES_LENGTH != 0) {
            NumOfBlocks++;
        }
    }

    // Block operations.
    for (unsigned long long int CurrentBlock = 1; CurrentBlock <= NumOfBlocks; CurrentBlock++) {
        std::string Block = "";

        // Getting a block of information.
        for (unsigned long long int g = 0; g < BLOCK_BYTES_LENGTH; g++) {
            Block.push_back(in[BLOCK_BYTES_LENGTH * (CurrentBlock - 1) + g]);
        }

        // Decrypting.
        AES_ctx_ECB_192 ctx;

        AES_init_ctx(&ctx, (const uint8_t *) key.data());
        AES_ECB_decrypt(&ctx, (uint8_t *) Block.data());

        Decrypted.append(Block);
    }

    return Decrypted;
}

#undef AES_256
#undef Nk
#undef Nr
#undef KEY_EXP_SIZE

#undef BLOCK_BYTES_LENGTH
