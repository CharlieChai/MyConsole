#include <iostream>
#include <string>
#include "console.h"

//
// Created by charlie01.chai on 2016/2/18.
//
Console::Console(){
    _user_input = "";
    cmd_map.insert(std::make_pair("history", &Console::cmdHistory));
    cmd_map.insert(std::make_pair("parse", &Console::cmdParse));
	cmd_map.insert(std::make_pair("help", &Console::cmdHelp));
    std::cout << sayHello() << std::endl;
}

Console::~Console(){
    //do something
}

Console &Console::accept(){
    while(1){
        CONSOLE_REDAY;
        getline(std::cin, _user_input);
        if(_user_input.empty()){
            CONSOLE_OUTPUT("Please enter something...");
            continue;
        }
        this->_cmd_history.push_back(_user_input);
        _lines++;
        param_list pl = split(_user_input, ' ');
        callFunc(pl);
        if(pl.front() == "exit"){
            break;
        }
        std::cin.clear();
    }
    return *this;
}

CMD_API Console::str Console::sayHello(){
    return "\n#### THIS IS MY CONSOLE ####";
};

void Console::callFunc(param_list pl){
    cmd_list::const_iterator iter = cmd_map.find(pl.front());
    if(iter != cmd_map.end()){
        (this->*(iter->second))(pl);
    }else{
        CONSOLE_OUTPUT("[Error] Command [" + pl.front() + "] not exist");
    }
}

Console::param_list Console::split(string &s, const char &c){
    vector<string> result;
    string _T_str;s += c;
    string::iterator it = s.begin();
    while(it != s.end()){
        if(*(it) != c){
            _T_str += *(it);
        }else if((*(it) == c)){
            result.insert(result.end(), _T_str);
            _T_str.clear();
        }
        it++;
    }
    return result;
}

CMD_API void Console::cmdHistory(param_list pl){
    for(str &s : _cmd_history){
        CONSOLE_OUTPUT(s);
    }

}

CMD_API void Console::cmdParse(param_list pl){
    for(string &str: pl){
        CONSOLE_OUTPUT(str);
    }
}

CMD_API void Console::cmdHelp(param_list pl) {
	map<string, pf>::iterator iter = Console::cmd_map.begin();
	while (iter != Console::cmd_map.end()) {
		CONSOLE_OUTPUT(">Command: "+iter->first);
		iter++;
	}
}
