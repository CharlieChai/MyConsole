#include <iostream>
#include "console.h"

//
// Created by charlie01.chai on 2016/2/18.
//
Console::Console() {
    _user_input = "";
    l.insert(std::make_pair("history", &Console::cmdHistory));
    std::cout << sayHello() << std::endl;
}

Console::~Console() {
    //do something
}

Console &Console::accept(){
    while(1) {
        CONSOLE_REDAY;
        getline(std::cin, _user_input);
        this->_cmd_history.push_back(_user_input);
        _lines++;
        callFunc(_user_input);
        if(_user_input == "exit"){
            break;
        }else{
            CONSOLE_OUTPUT("Command <"+ _user_input + "> not exist");
        }
        std::cin.clear();
    }
    return *this;
}

Console::str Console::sayHello(){
    return "\n#### THIS IS MY CONSOLE ####";
};

void Console::callFunc(const Console::str &key) {
    cmd_list::const_iterator iter = l.find(key);
    if(iter != l.end()) {
        (this->*(iter->second))(233);
    }else{
        //errors...
    }
}

//###############################
void Console::cmdHistory(int){
    for(str &s : _cmd_history){
        CONSOLE_OUTPUT(s);
    }
}

