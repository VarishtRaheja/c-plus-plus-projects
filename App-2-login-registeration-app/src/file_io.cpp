#include "../include/file_io.h"
#include <iostream>
#include <fstream>

// Function to return true/false if file exists
bool file_exists(const std::filesystem::path& p) {
    return std::filesystem::exists(p);
}

//Function to write registration details to file.
void write_user_record(const std::filesystem::path& file_path, const std::string& fname, const std::string& lname, const std::string& uname, const std::string& pword) {

    // Opening the file to write contents
    std::fstream file(file_path, std::ios::out);

    //Checking if file permission is valid
    if (file.is_open()) {
        // Columns
        file << "ID" << ',' << "First Name" << ',' << "Last Name" << ',' << "UserName" << ',' << "Password" << '\n';
        
        // Rows
        file << "1" << ',' << fname << ',' << lname << ',' << uname << ',' << pword << '\n';
        file.close();
    }
}


// Function to read/get contents from the file
std::vector<std::string> read_user_record(const std::filesystem::path& file_path) {
    std::vector<std::string> cols;

    if (file_exists(file_path)) {
        std::ifstream file{ file_path };
        std::string line;

        if (!file.is_open()) {
            return cols;
        }

        // Skip the header line
        std::getline(file, line);

        // Read the second line (first data row)
        if (std::getline(file, line)) {
            std::istringstream token_stream{ line };
            std::string token;
            
            int column_index = 0;
            // Extracting only the the part as required.
            while (std::getline(token_stream, token, ',')) {
                if (column_index==3 || column_index == 4) {
                   cols.push_back(token);
                   
                }
                ++column_index;
            }
        }
    }
    return cols;
}