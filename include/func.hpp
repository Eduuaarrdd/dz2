#ifndef FUNC_HPP_
#define FUNC_HPP_
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <regex>
#include "class.hpp"

std::vector<std::string> parser(std::string& command_str);
void create_queue (std::vector<std::string>& tokens, std::queue<IOperation*>& list_command, echo* mas_echo, cat* mas_cat, head* mas_head);

#endif // INCLUDE_FUNC_HPP_