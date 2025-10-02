#include "../include/input.h"
#include <iostream>
#include <limits>
#include <cctype>

// Function to handle the input data along with some error checking
std::string handle_user_input(const std::string_view& prompt) { // makes intention clear --> It wont be changed; i.e. only reading
    std::string input;
    while (true) {
        bool valid{ true };
        std::cout << prompt;
        std::getline(std::cin, input);

        // Check: Empty input field.
        if (input.empty()) {
            std::cerr << "Invalid input! This field cannot be empty. \n";
            continue;
        }

        // Check: Length of chars less than 2.
        if (input.length() < 2) {
            std::cerr << "Invalid input! Please ensure this field has more than 2 letters. \n";
            continue;
        }

        //Check: Only letters in a name.
        for (auto& i : input) {
            if (!std::isalpha(i)) {
                valid = false;
                std::cerr << "Invalid input! Please enter only alphabets. \n";
                break;
            }
        }
        if (valid) {
            break;
        }
    }
    return input;

}

//Function to handle username data. Validation checks included.
std::string handle_username_data(const std::string_view& prompt) {
    std::string username_input{};
    while (true) {
        // Similar to previous function.
        bool username_validity{ true };
        std::cout << prompt;
        std::getline(std::cin, username_input);
        if (username_input.empty()) {
            std::cerr << "Invalid input! This field cannot be empty. \n";
            continue;
        }
        for (auto& c : username_input) {
            if (!std::isalnum(c)) {
                std::cerr << "Username contains invalid character. Please use only letters and number. \n";
                username_validity = false;
                break;
            }
        }
        if (username_validity) {
            break;
        }
    }
    return username_input;
}

//Function to loop the user password if entered incorrectly and return the entered passwoord.
std::string handle_password_data(const std::string_view& prompt) {
    char confirm{ 'n' };
    std::string raw;
    while (true) {
        std::cout << prompt;

        //Storing the password;
        std::getline(std::cin, raw);
        std::cout << "Please confirm your password ('y'/'n'): ";
        std::cin >> confirm;

        // Clean the buffer from any leftover character.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (confirm == 'y') {
            return raw;
        }

    }
    return "";
}