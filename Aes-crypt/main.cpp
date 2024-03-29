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
                std::string *res1 = Red::EncryptAesCBC128(msg, key, iv);
                std::string *res2 = Red::GetHexArray(*res1);

                std::cout << std::endl << std::endl << *res2;

                delete res1;
                delete res2;

            } else if (mode == "CBC-192") {
                std::string *res1 = Red::EncryptAesCBC192(msg, key, iv);
                std::string *res2 = Red::GetHexArray(*res1);

                std::cout << std::endl << std::endl << *res2;

                delete res1;
                delete res2;

            } else if (mode == "CBC-256") {
                std::string *res1 = Red::EncryptAesCBC256(msg, key, iv);
                std::string *res2 = Red::GetHexArray(*res1);

                std::cout << std::endl << std::endl << *res2;

                delete res1;
                delete res2;

            } else if (mode == "ECB-128") {
                std::string *res1 = Red::EncryptAesECB128(msg, key);
                std::string *res2 = Red::GetHexArray(*res1);

                std::cout << std::endl << std::endl << *res2;

                delete res1;
                delete res2;

            } else if (mode == "ECB-192") {
                std::string *res1 = Red::EncryptAesECB192(msg, key);
                std::string *res2 = Red::GetHexArray(*res1);

                std::cout << std::endl << std::endl << *res2;

                delete res1;
                delete res2;

            } else if (mode == "ECB-256") {
                std::string *res1 = Red::EncryptAesECB256(msg, key);
                std::string *res2 = Red::GetHexArray(*res1);

                std::cout << std::endl << std::endl << *res2;

                delete res1;
                delete res2;
            }

            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

            std::cin.get();

        } else if (operation == "Decode") {
            std::cout << "\033[4mEnter a message(hex).\033[0m" << std::endl << "[\033[93mAes\033[0m/\033[94m" + mode + "\033[0m] > ";

            inp.clear();
            getline(std::cin, msg);
            std::cout << std::endl << std::endl;

            std::cout << "[\033[93mAes\033[0m/\033[94m" + mode + "\033[0m] \033[4mDecrypted message(str):\033[0m";
            std::cout << std::endl << std::endl;

            if (mode == "CBC-128") {
                std::string *res1 = Red::GetStrArray(msg.c_str());
                std::string *res2 = Red::DecryptAesCBC128(*res1, key, iv);

                std::cout << *res2;

                delete res1;
                delete res2;

            } else if (mode == "CBC-192") {
                std::string *res1 = Red::GetStrArray(msg.c_str());
                std::string *res2 = Red::DecryptAesCBC192(*res1, key, iv);

                std::cout << *res2;

                delete res1;
                delete res2;

            } else if (mode == "CBC-256") {
                std::string *res1 = Red::GetStrArray(msg.c_str());
                std::string *res2 = Red::DecryptAesCBC256(*res1, key, iv);

                std::cout << *res2;

                delete res1;
                delete res2;

            } else if (mode == "ECB-128") {
                std::string *res1 = Red::GetStrArray(msg.c_str());
                std::string *res2 = Red::DecryptAesECB128(*res1, key);

                std::cout << *res2;

                delete res1;
                delete res2;

            } else if (mode == "ECB-192") {
                std::string *res1 = Red::GetStrArray(msg.c_str());
                std::string *res2 = Red::DecryptAesECB192(*res1, key);

                std::cout << *res2;

                delete res1;
                delete res2;

            } else if (mode == "ECB-256") {
                std::string *res1 = Red::GetStrArray(msg.c_str());
                std::string *res2 = Red::DecryptAesECB256(*res1, key);

                std::cout << *res2;

                delete res1;
                delete res2;
            }

            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

            std::cin.get();
        }
    }
}
