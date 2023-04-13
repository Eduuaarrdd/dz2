#ifndef CLASS_HPP_
#define CLASS_HPP_
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

class IOperation
{
    public:
    virtual void HandleEndOfInput() = 0;
    virtual void ProcessLine(const std::string& s) = 0;
    virtual void SetNextOperation(IOperation* command) = 0;
};

class cat: public IOperation
{

    public: 
    
    cat(); 
    cat (const std::string& file_name);
    void ProcessLine(const std::string& s);
    void SetNextOperation(IOperation* command);
    void HandleEndOfInput();

    private:

    std::string str;

};

class echo: public IOperation
{
    public:

    echo(); 
    echo (const std::string& s);
    void ProcessLine(const std::string& s);
    void SetNextOperation(IOperation* commanda);
    void HandleEndOfInput();

    private:

    std::string str;

};

class head: public IOperation
{
    public:
    head(); 
    head (const std::string& s);
    void ProcessLine(const std::string& s); 
    void SetNextOperation(IOperation* commanda);
    void HandleEndOfInput();

    private:

    std::string str;
    int N;

};

#endif // INCLUDE_CLASS_HPP_