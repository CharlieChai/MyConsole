
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
    typedef vector<string> param_list;
    typedef void (Console::*pf)(param_list);
    typedef map<string, pf> cmd_list;

    Console();
    ~Console();
    Console &accept();

    void cmdHistory(param_list);
    void cmdParse(param_list);
    cmd_list l;
    void callFunc(const str&, param_list);
    param_list split(string &, const char &);
private:
    uint16_t _lines = 0;
    str _user_input;
    std::vector<str> _cmd_history;
    str sayHello();
};

#endif //C_PRIMER_CONSOLE_H
