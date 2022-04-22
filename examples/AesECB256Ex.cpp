#include <iostream>
#include <string>

#include "../RedLibrary/EncryptionAlgorithms/AesECB256.h"
#include "../RedLibrary/Hex.h"

int main() {
    std::string key = "0123456789abcdef1234567812345678";
    std::string in  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesECB256(in, key);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::cout << "Encrypted(hex): '" << *EncryptedHex << "'." << std::endl;

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesECB256(*ForDecrypt, key);

    std::cout << "Decrypted(str): '" << *Decrypted << "'." << std::endl;

    delete EncryptedStr;
    delete EncryptedHex;
    
    delete ForDecrypt;
    delete Decrypted;

    return 0;
}