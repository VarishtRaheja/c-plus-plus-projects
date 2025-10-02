// App-2-login-registration-app.cpp : Defines the entry point for the application.

//Adding all the dependencies
#include "../include/encryption.h"
#include "../include/file_io.h"
#include "../include/input.h"
#include <iostream>

//Creating a custom filepath function
std::filesystem::path filePath(const std::string &filename) {
	// Get the path of the current file
	std::filesystem::path source_path{ __FILE__ };

	// Get the directory containing the source directory
	std::filesystem::path source_dir{ source_path.parent_path() };

	//Create a subdirectory called "login_details"
	std::filesystem::path login_dir{ source_dir.parent_path() / "Login_Details" };
	std::filesystem::create_directory(login_dir); // Creates if not exist

	//Final file path
	std::filesystem::path login_path{ login_dir / filename };

	return login_path;
}

int main()
{
	const std::filesystem::path fp{ filePath("user_details.txt")};

	// Begin...
	std::cout << "Welcome to RealityHitsHard.com\n Here we talk about all topics except reality. \n";

	if (!file_exists(fp)) {
		//Writing user input to file
		std::cout << "Please provide your details to register and enjoy all our channels! \n";

		const std::string first_name = handle_user_input("Please enter your first name: ");
		const std::string last_name = handle_user_input("Please enter your last name: ");
		const std::string user_name = handle_username_data("Please enter your username: ");
		const std::string user_password = handle_password_data("Please enter your password: ");

		std::cout << "Registering new user.\n";
		write_user_record(fp, first_name, last_name, user_name, ceasar_style_encryption(user_password));
		std::cout << "Registration Complete! \n";
	}
	
	//Login process to confirm details on file.
	std::cout << "\n";
	while (true) {
		std::cout << "Please login with your credentials. \n";
		const std::string entered_username{ handle_username_data("Please enter your username: ") };
		const std::string entered_password{ handle_password_data("Please enter your password: ") };

		auto cols = read_user_record(fp);
		if (cols.size() >= 2 && entered_username == cols[0] && entered_password == ceasar_style_decryption(cols[1])) {
			std::cout << "Welcome Back, " << cols[0] << '\n';
			break;
		}
		else {
			std::cerr << "Invalid credentials! Please check username and password. \n";
		}
	}

	//End
	return 0;
}
