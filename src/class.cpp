    #include "class.hpp"
    
    cat::cat() {} 
    cat::cat (const std::string& file_name)
    {
        std::ifstream F;
        F.open(file_name);
        if (F.is_open())
        {
        std::string line;
            while (getline(F, line))
            {
                str = str+line+"\n";
            }  
        F.close();
        str.pop_back(); 
        } else {std::cerr<<"ошибка неверное имя файла: "<<file_name<<std::endl;}

    }
    
    void cat::ProcessLine(const std::string& s)
    {
       str = s + "\n" + str; 
    }

    void cat::SetNextOperation(IOperation* command)
    {
        command->ProcessLine(str);
    }

    void cat::HandleEndOfInput()
    {
        std::cout<<str<<std::endl;
    }

    echo::echo() {} 

    echo::echo (const std::string& s)
    {
        str = s;
    }

    void echo::ProcessLine(const std::string& s) {}

    void echo::SetNextOperation(IOperation* commanda)
    {
        commanda->ProcessLine(str);
    }

    void echo::HandleEndOfInput()
    {
        std::cout<<str<<std::endl;
    }

    head::head() {} 

    head::head (const std::string& s)
    {
        N = stoi(s);
        if (N<0) {std::cerr<<"ошибка неверное число около head: "<<N<<std::endl;}
    }

    void head::ProcessLine(const std::string& s) 
    {
        if (N != 0)
        {
        int pos = 0;
        for (int i = 0; i < N; i++)
        {
            pos = s.find("\n", pos);
            if (pos == -1) {break;}
            pos++;
        }
        str = s.substr(0, --pos);
        } else {str.clear();}
        
    }

    void head::SetNextOperation(IOperation* commanda)
    {
        commanda->ProcessLine(str);
    }

    void head::HandleEndOfInput()
    {
        std::cout<<str<<std::endl;
    }