#pragma once

#include <filesystem>
#include <string>


bool file_exists(const std::filesystem::path& p);
void write_user_record(
	const std::filesystem::path& file_path, 
	const std::string &fname , 
	const std::string &lname ,
	const std::string &uname ,
	const std::string &pword
);
std::vector<std::string> read_user_record(const std::filesystem::path& file_path);