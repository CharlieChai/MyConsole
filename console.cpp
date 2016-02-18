#include "console.hpp"

//
// Created by charlie01.chai on 2016/2/18.
//
Console::Console() {
    _user_input = "";
    std::cout << sayHello() << std::endl;
}

Console &accept(){
    while(1) {
        CONSOLE_REDAY;
        getline(std::cin, _user_input);
        this->_cmd_history.push_back(_user_input);
        _lines++;
//            cmd_list[_user_input](1);
        if(_user_input == "exit"){
            break;
        }else{
            CONSOLE_OUTPUT("ERROR");
        }
        std::cin.clear();
    }
    return *this;
}

CMD_API void Console::cmdHistory(int){
    for(str &s : _cmd_history){
        CONSOLE_OUTPUT(s);
    }
}

str Console::sayHello(){
    return "\n#### THIS IS MY CONSOLE ####";
};