#include <iostream>
#include <string>

#include "Aes/AesCBC128.h"
#include "Aes/AesCBC192.h"
#include "Aes/AesCBC256.h"
#include "Aes/AesECB128.h"
#include "Aes/AesECB192.h"
#include "Aes/AesECB256.h"
#include "Hex.h"

int main() {
    // Variables.
    std::string inp;

    std::string operation;
    std::string mode;

    std::string key;
    std::string iv;
    std::string msg;

    while (true) {

        // Operations.
        while (true) {
            system("clear");
            std::cout << "\033[4mChoose operation:\033[0m 1)Encode 2)Decode.";

            std::cout << std::endl << std::endl << "[\033[93mAes\033[0m]  > ";

            inp.clear();
            key.clear();
            iv.clear();
            msg.clear();

            std::cin >> inp;

            // Operation selection.
            if (inp == "1" || inp == "2") {
                if (inp == "1") {
                    operation = "Encode";

                } else if (inp == "2") {
                    operation = "Decode";
                }

                break;
            }
        }

        // Mode selection.
        while (true) {
            system("clear");
            std::cout << "\033[4mChoose mode:\033[0m 1)CBC-128. 2)CBC-192. 3)CBC-256. 4)ECB-128. 5)ECB-192. 6)ECB-256.";
            std::cout << std::endl << std::endl << "[\033[93mAes\033[0m]  > ";

            std::cin >> inp;

            if (inp == "1" || inp == "2" || inp == "3" || inp == "4" || inp == "5" || inp == "6") {
                if (inp == "1") {
                    mode = "CBC-128";

                } else if (inp == "2") {
                    mode = "CBC-192";

                } else if (inp == "3") {
                    mode = "CBC-256";

                } else if (inp == "4") {
                    mode = "ECB-128";

                } else if (inp == "5") {
                    mode = "ECB-192";

                } else if (inp == "6") {
                    mode = "ECB-256";
                }

                break;
            }
        }

        // Entering key.
        {
            system("clear");
            std::cout << "\033[4mEnter a key.\033[0m" << std::endl << "[\033[93mAes\033[0m/\033[94m" + mode + "\033[0m] > ";

            std::cin.ignore();
            inp.clear();
            getline(std::cin, key);
            std::cout << std::endl << std::endl;
        }

        // Entering iv.
        if (mode == "CBC-128" || mode == "CBC-192" || mode == "CBC-256") {
            std::cout << "\033[4mEnter an initialization vector.\033[0m" << std::endl << "[\033[93mAes\033[0m/\033[94m" + mode + "\033[0m] > ";

            inp.clear();
            getline(std::cin, iv);
            std::cout << std::endl << std::endl;
        }

        // Encrypting.
        if (operation == "Encode") {
            std::cout << "\033[4mEnter a message(str).\033[0m" << std::endl << "[\033[93mAes\033[0m/\033[94m" + mode + "\033[0m] > ";

            inp.clear();
            getline(std::cin, msg);
            std::cout << std::endl << std::endl;

            std::cout << "[\033[93mAes\033[0m/\033[94m" + mode + "\033[0m] \033[4mEncrypted message(hex):\033[0m";

            if (mode == "CBC-128") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptAesCBC128(msg, key, iv));

            } else if (mode == "CBC-192") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptAesCBC192(msg, key, iv));

            } else if (mode == "CBC-256") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptAesCBC256(msg, key, iv));

            } else if (mode == "ECB-128") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptAesECB128(msg, key));

            } else if (mode == "ECB-192") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptAesECB192(msg, key));

            } else if (mode == "ECB-256") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptAesECB256(msg, key));
            }

            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

            std::cin.get();

        } else if (operation == "Decode") {
            std::cout << "\033[4mEnter a message(hex).\033[0m" << std::endl << "[\033[93mAes\033[0m/\033[94m" + mode + "\033[0m] > ";

            inp.clear();
            getline(std::cin, msg);
            std::cout << std::endl << std::endl;
            std::cout << msg.length() << ":" << msg << std::endl;

            std::cout << "[\033[93mAes\033[0m/\033[94m" + mode + "\033[0m] \033[4mDecrypted message(str):\033[0m";
            std::cout << std::endl << std::endl;

            if (mode == "CBC-128") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptAesCBC128(Red::GetStrArray(msg), key, iv);

            } else if (mode == "CBC-192") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptAesCBC192(Red::GetStrArray(msg), key, iv);

            } else if (mode == "CBC-256") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptAesCBC256(Red::GetStrArray(msg), key, iv);

            } else if (mode == "ECB-128") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptAesECB128(Red::GetStrArray(msg), key);

            } else if (mode == "ECB-192") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptAesECB192(Red::GetStrArray(msg), key);

            } else if (mode == "ECB-256") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptAesECB256(Red::GetStrArray(msg), key);
            }

            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

            std::cin.get();
        }
    }

        // Encrypting.
        /*if (inp == "1") {
            while (true) {
                system("clear");
                std::cout << "\033[4mChoose mode:\033[0m 1)CBC-128. 2)CBC-192. 3)CBC-256. 4)ECB-128. 5)ECB-192. 6)ECB-256.";
                std::cout << std::endl << std::endl << "[\033[93mAes\033[0m]  > ";

                std::cin >> inp;

                if (inp == "1") { // CBC-128.
                    system("clear");
                    std::cout << "\033[4mEnter a key.\033[0m" << std::endl << "[\033[93mAes\033[0m/\033[94mCBC-128\033[0m] > ";

                    std::cin.ignore();
                    inp.clear();
                    getline(std::cin, key);
                    std::cout << std::endl << std::endl;

                    std::cout << "\033[4mEnter an initialization vector.\033[0m" << std::endl << "[\033[93mAes\033[0m/\033[94mCBC-128\033[0m] > ";

                    std::cin.ignore();
                    inp.clear();
                    getline(std::cin, iv);
                    std::cout << std::endl << std::endl;

                    std::cout << "\033[4mEnter a message(str).\033[0m" << std::endl << std::endl << "[\033[93mAes\033[0m/\033[94mCBC-128\033[0m] > ";

                    std::cin.ignore();
                    inp.clear();
                    getline(std::cin, msg);
                    std::cout << std::endl << std::endl;

                    std::cout << "[\033[93mAes\033[0m/\033[94mCBC-128\033[0m] \033[4mEncrypted message(hex):\033[0m";
                    std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptAesCBC128(msg, key, iv));
                    std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

                    std::cin.get();

                    break;

                } else if (inp == "2") { // CBC-192.

                } else if (inp == "3") { // CBC-256.

                } else if (inp == "4") { // ECB-128.

                } else if (inp == "5") { // ECB-192.

                } else if (inp == "6") { // ECB-256.

                }
            }

        // Decrypting.
        } else if (inp == "2") {
            while (true) {
                system("clear");
                std::cout << "\033[4mChoose mode:\033[0m 1)CBC-128. 2)CBC-192. 3)CBC-256. 4)ECB-128. 5)ECB-192. 6)ECB-256.";
                std::cout << std::endl << std::endl << "[\033[93mAes\033[0m]  > ";

                std::cin >> inp;

                if (inp == "1") {
                    system("clear");
                    std::cout << "\033[4mEnter a key.\033[0m" << std::endl << "[\033[93mAes\033[0m/\033[94mCBC-128\033[0m] > ";

                    std::cin.ignore();
                    inp.clear();
                    getline(std::cin, key);
                    std::cout << std::endl << std::endl;
                    std::cout << key.length() << ":" << key << std::endl;

                    std::cout << "\033[4mEnter an initialization vector.\033[0m" << std::endl << "[\033[93mAes\033[0m/\033[94mCBC-128\033[0m] > ";

                    inp.clear();
                    getline(std::cin, iv);
                    std::cout << std::endl << std::endl;
                    std::cout << iv.length() << ":" << iv << std::endl;

                    std::cout << "\033[4mEnter a message(hex).\033[0m" << std::endl << std::endl << "[\033[93mAes\033[0m/\033[94mCBC-128\033[0m] > ";

                    inp.clear();
                    getline(std::cin, msg);
                    std::cout << std::endl << std::endl;
                    std::cout << msg.length() << ":" << msg << std::endl;

                    std::cout << "[\033[93mAes\033[0m/\033[94mCBC-128\033[0m] \033[4mDecrypted message(str):\033[0m";
                    std::cout << std::endl << std::endl;

                    std::string a = Red::GetStrArray(msg.c_str());

                    std::cout << Red::DecryptAesCBC128(Red::GetStrArray(msg), key, iv);
                    std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

                    std::cin.get();

                    break;

                } else if (inp == "2") {

                } else if (inp == "3") {

                } else if (inp == "4") {

                } else if (inp == "5") {

                } else if (inp == "6") {

                }
            }
        }
    }*/
}
