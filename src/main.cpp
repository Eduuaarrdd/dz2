
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "func.hpp"
#include "class.hpp"

int main(int argc, char *argv[])
{
    std::string command_str = argv[1];
    std::vector<std::string> tokens;

    tokens = parser(command_str);

    std::queue<IOperation*> list_command;
    echo mas_echo[tokens.size()];
    cat mas_cat[tokens.size()];
    head mas_head[tokens.size()];

    create_queue(tokens, list_command, mas_echo, mas_cat, mas_head);
    
    int size = list_command.size();
    
    IOperation* operation = nullptr;

    for (int i = 0; i < size-1; i++)
    {
    operation = list_command.front();
    list_command.pop();
    operation -> SetNextOperation(list_command.front());
    }
    
    list_command.front()->HandleEndOfInput();

    return 0;
}