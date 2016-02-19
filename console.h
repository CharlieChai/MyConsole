
#ifndef C_PRIMER_CONSOLE_H
#define C_PRIMER_CONSOLE_H

#include <functional>
#include <vector>
#include <map>

#define CONSOLE_IDENTIFIER ">>"
#define CONSOLE_OUTPUT(x) (std::cout << x << "\n" )
#define CONSOLE_REDAY (std::cout << CONSOLE_IDENTIFIER)
#define CONSOLE_NEWLINE (std::cout << std::endl )
#define CMD_API

using namespace std;

class Console {

public:
    typedef std::string str;
    typedef void (Console::*pf)(int);
    typedef map<string, pf> cmd_list;

    Console();
    Console &accept();
    void cmdHistory(int);
    cmd_list l;
    void callFunc(const str&);
private:
    uint16_t _lines = 0;
    str _user_input;
    std::vector<str> _cmd_history;
    str sayHello();
};

#endif //C_PRIMER_CONSOLE_H
