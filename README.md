# AES_Implementation [![](https://img.shields.io/apm/l/vim-mode)](https://github.com/Red-company/RES_Implementation/blob/main/LICENSE.md) [![](https://img.shields.io/github/repo-size/vladimirrogozin/AES_Implementation)](https://github.com/vladimirrogozin/AES_Implementation)

## What is it?

This is a small and portable C++17 implementation of the Advanced Encryption Standartd(AES). It is a part of [RedLibrary](https://github.com/Red-company/RedLibrary).

## Where to use?

AES can be used everywhere you need. It's got strong encryption level and has pretty good perfomance. But if you're looking for algorithm for specific task, I have an option with excess level of encryption, here it is: [RES](https://github.com/Red-company/RES_Implementation).

## What does AES consist of?
AES includes 2 encryption modes: [ECB](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_.28ECB.29) and [CBC](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Cipher_Block_Chaining_.28CBC.29) with 3 key length cases for each of them:

* ECB
  * AesECB 128 bits key
  * AesECB 192 bits key
  * AesECB 256 bits key
  
* CBC
  * AesCBC 128 bits key
  * AesCBC 192 bits key
  * AesCBC 256 bits key
  
## How to use it?

There are 7 header files(6 with algorithms and 1 with shared definitions) and 6 source files(for each of algorithm).

```C
// AesECB128.h
const std::string EncryptAesECB128(const std::string& in, const std::string_view key);
const std::string DecryptAesECB128(const std::string& in, const std::string_view key);

// AesECB192.h
const std::string EncryptAesECB192(const std::string& in, const std::string_view key);
const std::string DecryptAesECB192(const std::string& in, const std::string_view key);

// AesECB256.h
const std::string EncryptAesECB256(const std::string& in, const std::string_view key);
const std::string DecryptAesECB256(const std::string& in, const std::string_view key);

// AesCBC128.h
const std::string EncryptAesCBC128(const std::string& in, const std::string_view key, const std::string_view iv);
const std::string DecryptAesCBC128(const std::string& in, const std::string_view key, const std::string_view iv);

// AesCBC192.h
const std::string EncryptAesCBC192(const std::string& in, const std::string_view key, const std::string_view iv);
const std::string DecryptAesCBC192(const std::string& in, const std::string_view key, const std::string_view iv);

// AesCBC256.h
const std::string EncryptAesCBC256(const std::string& in, const std::string_view key, const std::string_view iv);
const std::string DecryptAesCBC256(const std::string& in, const std::string_view key, const std::string_view iv);
```
**Tech notes:**
 * Padding is provided only for "in" params. "Iv" should equals 16 bytes. Key length(in bytes) is calculated using the formula: `KEY_LENGTH / 8`.
 * ECB mode is considered unsafe for most uses and is not implemented in streaming mode. See [wikipedia's article on ECB](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_(ECB)) for more details.
 * This library is designed for small code size and simplicity, intended for cases where small binary size, low memory footprint and portability is more important than high performance.

**Notes:**
 * If you want to route result of encryption to `std::cout`, you should convert string to hexadecimal system, in other way you will get bad output!
  * **Convertion functions are included in each of examples.**
 * There is no built-in error checking or protection from out-of-bounds memory access errors as a result of malicious input.

Do contact me if you have improvements to the code(contacts are in each of source files). 

All material in this repository is in the public domain.
