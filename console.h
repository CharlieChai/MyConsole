
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

    Console();

    Console &accept(){
        while(1) {
            CONSOLE_REDAY;
            getline(std::cin, _user_input);
            this->_cmd_history.push_back(_user_input);
            _lines++;
            cmd_list[_user_input](1);
            if(_user_input == "exit"){
                break;
            }else{
                CONSOLE_OUTPUT("ERROR");
            }
            std::cin.clear();
        }
        return *this;
    }

    CMD_API void cmdHistory(int){
        for(str &s : _cmd_history){
            CONSOLE_OUTPUT(s);
        }
    }

private:

    std::map<str, std::function<void (int)>> cmd_list = {
            {"history", cmdHistory}
    };
    uint16_t _lines = 0;
    str _user_input;
    std::vector<str> _cmd_history;

    str sayHello(){
        return "\n#### THIS IS MY CONSOLE ####";
    };
};

Console::Console() {
    _user_input = "";
    std::cout << sayHello() << std::endl;
}
#endif //C_PRIMER_CONSOLE_H
