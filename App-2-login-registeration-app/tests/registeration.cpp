//#include "main.h"
//#include <regex>
//#include <sstream>
//#include <cmath>
//
//// Function to return true/false if file exists
//bool file_exists(const std::filesystem::path &p) {
//    return std::filesystem::exists(p);
//}
//
//// Function to handle the input data along with some error checking
//std::string handle_user_input(const std::string_view& prompt) { // makes intention clear --> It wont be changed; i.e. only reading
//    std::string input;
//    while (true) {
//        bool valid{ true };
//        std::cout << prompt;
//        std::getline(std::cin, input);
//
//        // Check: Empty input field.
//        if (input.empty()) {
//            std::cerr << "Invalid input! This field cannot be empty. \n";
//            continue;
//        }
//
//        // Check: Length of chars less than 2.
//        if (input.length() < 2) {
//            std::cerr << "Invalid input! Please ensure this field has more than 2 letters. \n";
//            continue;
//        }
//        
//        //Check: Only letters in a name.
//        for (auto& i : input) {
//            if (!std::isalpha(i)) {
//                valid = false;
//                std::cerr << "Invalid input! Please enter only alphabets. \n";
//                break;
//            }
//        }
//        if (valid) {
//            break;
//        }
//    }
//    return input;
//
//}
//
//std::string handle_username_data(const std::string_view& prompt) {
//    std::string username_input{};
//    while (true) {
//        // Similar to previous function.
//        bool username_validity{ true };
//        std::cout << prompt;
//        std::getline(std::cin, username_input);
//        if (username_input.empty()) {
//            std::cerr << "Invalid input! This field cannot be empty. \n";
//            continue;
//        }
//        for (auto& c : username_input) {
//            if (!std::isalnum(c)) {
//                std::cerr << "Username contains invalid character. Please use only letters and number. \n";
//                username_validity = false;
//                break;
//            }
//        }
//        if (username_validity) {
//            break;
//        }
//    }
//    return username_input;
//}
//
//
///*
//Function that takes a password, including special chars and encrypts it.
//Simple encrytion process. Convert digits and non-digits seperately.
//*/
//std::string ceasar_style_encryption(const std::string& user_password) {
//    std::string encrypt_password;
//
//    //Pre-allocating space for memory.
//    encrypt_password.reserve(user_password.size());
//    for (auto& c : user_password) {
//        // Simple encryption for letters and special chars.
//        if (std::isalpha(c) || !std::isalnum(c)) {
//            if (std::islower(c)) {
//                encrypt_password += ('a' + (c - 'a' + 3) % 26);
//            }
//            else {
//                encrypt_password += ('A' + (c - 'A' + 3) % 26);
//            }
//        }
//        if (std::isdigit(c)) {
//            //encrypting digits by taking the square of each digit.
//            int result = c - '0';
//            int sq = result * result;
//            encrypt_password += std::to_string(sq);
//        }
//        
//    }
//
//    return encrypt_password;
//}
//
//
////Function to loop the user password if entered incorrectly.
//std::string handle_password_data(const std::string_view& prompt) {
//    char confirm{ 'n' };
//    std::string hash_encrypted_password;
//    while (true) {
//        std::cout << prompt;
//        
//        //Storing the password
//        std::string get_password;
//        std::getline(std::cin, get_password);
//        std::cout << "Please confirm your password ('y'/'n'): ";
//        std::cin >> confirm;
//
//        // Clean the buffer from any leftover character.
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//        if (confirm == 'y') {
//
//            std::cout << "Password has been set. \n";
//            hash_encrypted_password = ceasar_style_encryption(get_password);
//            break;
//        }
//
//    }
//    return hash_encrypted_password;
//}
//
//// Function to write details to file
//void write_to_file(const std::filesystem::path &file_path) {
//    short int id{ 1 };
//
//    std::cout << "You do not have an account with us. \n";
//    std::cout << "Please register yourself first: \n";
//
//    // Storing details in variables
//    std::string first_name = handle_user_input("Please enter your first name: ");
//    std::string last_name = handle_user_input("Please enter your last name: ");
//    std::string username = handle_username_data("Please enter your username: ");
//    std::string encrypted_password = handle_password_data("Please enter your password: ");
//
//    // Openign the file to write contents
//    std::fstream file(file_path, std::ios::out);
//
//    //Checking if file permission is valid
//    if (file.is_open()) {
//        // Columns
//        file << "ID" << ',' << "First Name" << ',' << "Last Name" << ',' << "UserName" << ',' << "Password" << '\n';
//        // Rows
//        file << id << ',' << first_name << ',' << last_name << ',' << username << ',' << encrypted_password << '\n';
//        std::cout << "Contents written to " << filename << '\n';
//        ++id;
//        file.close();
//    }
//}
//
//
////Function to decrypt the password
//std::string ceasar_style_decryption(const std::string& user_password) {
//    std::string decrypt_password;
//
//    //Pre-allocating space for memory.
//    decrypt_password.reserve(user_password.size());
//    for (auto& c : user_password) {
//        if (std::isalpha(c) || !std::isalnum(c)) {
//            if (std::islower(c)) {
//                decrypt_password += ('a' + (c - 'a' - 3 + 26) % 26);
//            }
//            else {
//                decrypt_password += ('A' + (c - 'A' + 3 + 26) % 26);
//            }
//        }
//        if (std::isdigit(c)) {
//            //decrypting digits by taking the square-root
//            int result = c - '0';
//            int sq = static_cast<int>(std::sqrt(result));
//            decrypt_password += std::to_string(sq);
//        }
//
//    }
//
//    return decrypt_password;
//}
//
//
//// Function to read/get contents from the file
//std::vector<std::string> get_file_contents(const std::filesystem::path& file_path) {
//    std::vector<std::string> add_tokens;
//
//    if (file_exists(file_path)) {
//        std::ifstream file{ file_path };
//        std::string line;
//
//        if (!file.is_open()) {
//            return add_tokens;
//        }
//
//        // Skip the header line
//        std::getline(file, line);
//
//        // Read the second line (first data row)
//        if (std::getline(file, line)) {
//            std::istringstream token_stream{ line };
//            std::string token;
//            
//            int column_index = 0;
//            // Extracting only the the part as required.
//            while (std::getline(token_stream, token, ',')) {
//                if (column_index==3 || column_index == 4) {
//                   add_tokens.push_back(token);
//                   
//                }
//                ++column_index;
//            }
//        }
//    }
//    return add_tokens;
//}
//
////Function....
//std::string some_func(const std::filesystem::path& file_path) {
//    if (!file_exists(file_path)) {
//        write_to_file(file_path);
//    }
//    std::cout << "Please login to successfully continue. \n";
//    std::cout << "Please confirm your details below: \n";
//    std::string login_user_username = handle_username_data("Please enter your username: ");
//
//    //Get user entered password.
//    std::string login_user_password;
//    std::cout << "Please enter your password: ";
//    std::getline(std::cin, login_user_password);
//
//    // Decrypt the password on disk
//    auto tokens = get_file_contents(file_path);
//    std::string u = tokens[0];
//    std::string p = tokens[1];
//    std::string decrypted_password = decryption(p);
//
//    if (login_user_username == u && login_user_password == decrypted_password) {
//        //TO-DO: print login matches, enjooy your time.
//        std::cout << "Credentials match. Welcome. \n";
//    }
//    else {
//        std::cerr << "Username or password dont match. Please try again! \n";
//    }
//
//    return {"",""};
//}
//
////std::string extract_contents_from_file(const std::filesystem::path& file_path) {
////    
////    std::string file_contents = get_file(file_path);
////    std::regex re(","); // Define the comma as the delimiter
////    std::sregex_token_iterator it(file_contents.begin(), file_contents.end(), re, -1);
////    std::sregex_token_iterator end;
////    std::vector<std::string> result(it, end);
////    return  result[0];
////}