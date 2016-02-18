
#ifndef C_PRIMER_CONSOLE_H
#define C_PRIMER_CONSOLE_H

#define CONSOLE_IDENTIFIER ">>"
#define CONSOLE_OUTPUT(x) (std::cout << x << "\n" )
#define CONSOLE_REDAY (std::cout << CONSOLE_IDENTIFIER)
#define CONSOLE_NEWLINE (std::cout << std::endl )
#define CMD_API

using namespace std;

class Console {

public:
    typedef std::string str;
    typedef std::function<void (int)> cmd_fn;
    void (Console::*pf)(int);
    Console();
    void cmdHistory(int);
//    std::map<str, pf> cmd_list = {
//            {"history", &cmdHistory}
//    };

private:
    uint16_t _lines = 0;
    str _user_input;
    std::vector<str> _cmd_history;
    str sayHello();
};

#endif //C_PRIMER_CONSOLE_H
