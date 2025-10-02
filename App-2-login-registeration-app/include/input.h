#pragma once

#include <string>
#include <string_view>

std::string handle_user_input(const std::string_view& prompt);
std::string handle_username_data(const std::string_view& prompt);
std::string handle_password_data(const std::string_view& prompt);