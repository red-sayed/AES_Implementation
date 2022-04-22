#include <iostream>
#include <string>

#include "../RedLibrary/EncryptionAlgorithms/AesCBC256.h"
#include "../RedLibrary/Hex.h"

int main() {
    std::string key = "0123456789abcdef1234567812345678";
    std::string in  = "0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string *EncryptedStr = Red::EncryptAesCBC256(in, key, iv);
    std::string *EncryptedHex = Red::GetHexArray(*EncryptedStr);

    std::cout << "Encrypted(hex): '" << *EncryptedHex << "'." << std::endl;

    std::string *ForDecrypt = Red::GetStrArray(*EncryptedHex);
    std::string *Decrypted  = Red::DecryptAesCBC256(*ForDecrypt, key, iv);

    std::cout << "Decrypted(str): '" << *Decrypted << "'." << std::endl;

    delete EncryptedStr;
    delete EncryptedHex;
    
    delete ForDecrypt;
    delete Decrypted;

    return 0;
}