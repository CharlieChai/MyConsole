#include <iostream>
#include "console.h"
#include <boost/unordered_map.hpp>

//
// Created by charlie01.chai on 2016/2/18.
//
Console::Console() {
    _user_input = "";
    l.insert(std::make_pair("history", &Console::cmdHistory));
    std::cout << sayHello() << std::endl;
}

Console &Console::accept(){
    while(1) {
        CONSOLE_REDAY;
        getline(std::cin, _user_input);
        this->_cmd_history.push_back(_user_input);
        _lines++;
        callFunc(l, _user_input);
        if(_user_input == "exit"){
            break;
        }else{
            CONSOLE_OUTPUT("ERROR");
        }
        std::cin.clear();
    }
    return *this;
}


void Console::callFunc(cmd_list &cmd, Console::str &func) {
    auto iter = cmd.find(func);
    if(iter != cmd.end()) {
        (*iter->second)(1);
    }else{
        //errors...
    }
}

CMD_API void Console::cmdHistory(int){
    for(str &s : _cmd_history){
        CONSOLE_OUTPUT(s);
    }
}

Console::str Console::sayHello(){
    return "\n#### THIS IS MY CONSOLE ####";
};