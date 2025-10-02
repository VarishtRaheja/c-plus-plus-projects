#include "../include/encryption.h"
#include <cmath> // --> for std::sqrt

/*
Function that takes a password, including special chars and encrypts it.
Simple encryption process. Convert digits and non-digits separately.
*/
std::string ceasar_style_encryption(const std::string& user_password) {
    std::string encrypt_password;

    //Pre-allocating space for memory.
    encrypt_password.reserve(user_password.size());
    for (auto& c : user_password) {
        // Simple encryption for letters and special chars.
        if (std::isalpha(c) || !std::isalnum(c)) {
            if (std::islower(c)) {
                encrypt_password += ('a' + (c - 'a' + 3) % 26);
            }
            else {
                encrypt_password += ('A' + (c - 'A' + 3) % 26);
            }
        }
        if (std::isdigit(c)) {
            //encrypting digits by taking the square of each digit.
            int result = c - '0';
            int sq = result * result;
            encrypt_password += std::to_string(sq);
        }

    }

    return encrypt_password;
}

//Function to decrypt the password
std::string ceasar_style_decryption(const std::string& user_password) {
    std::string decrypt_password;

    //Pre-allocating space for memory.
    decrypt_password.reserve(user_password.size());
    for (auto& c : user_password) {
        if (std::isalpha(c) || !std::isalnum(c)) {
            if (std::islower(c)) {
                decrypt_password += ('a' + (c - 'a' - 3 + 26) % 26);
            }
            else {
                decrypt_password += ('A' + (c - 'A' + 3 + 26) % 26);
            }
        }
        if (std::isdigit(c)) {
            //decrypting digits by taking the square-root
            int result = c - '0';
            decrypt_password += std::to_string(static_cast<int>(std::sqrt(result)));
        }

    }

    return decrypt_password;
}