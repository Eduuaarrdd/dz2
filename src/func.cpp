#include "class.hpp"
#include "func.hpp"

std::vector<std::string> parser(std::string& command_str)
{
    std::regex reg (R"( \| )");
    std::sregex_token_iterator iter(command_str.begin(), command_str.end(), reg, -1);
    std::sregex_token_iterator end;

    std::vector<std::string> tokens(iter, end);
    return tokens;
};

void create_queue (std::vector<std::string>& tokens, std::queue<IOperation*>& list_command, echo* mas_echo, cat* mas_cat, head* mas_head )
{
    std::vector<std::string> operation {"echo ","cat ","head "};
    int pos = 0;
    for ( int i = 0; i != tokens.size(); ++i)
    {
        for (int flag = 0; flag < operation.size(); ++flag)
        {
            pos = tokens[i].find(operation[flag]);
            if (pos == 0)
            {
                switch (flag)
                {
                    case 0: 
                    {
                    mas_echo[i] = echo((tokens[i]).substr(5));
                    list_command.push(&mas_echo[i]);
                    flag = operation.size();
                    break;
                    }
                    case 1: 
                    {
                    mas_cat[i] = cat((tokens[i]).substr(4));
                    list_command.push(&mas_cat[i]);
                    flag = operation.size();
                    break;
                    }
                    case 2:
                    {
                    mas_head[i] = head((tokens[i]).substr(5));
                    list_command.push(&mas_head[i]);
                    flag = operation.size();
                    break;
                    }
                }
            } else if ((pos == -1) && (flag == operation.size()-1)) { std::cerr<<"ошибка ввода команды: "<<tokens[i]<<std::endl;}
        }
    }

};
