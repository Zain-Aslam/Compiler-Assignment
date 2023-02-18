#include <map>
#include <functional>
#include <string>
#include <iostream>

typedef std::map< std::string, std::function<void(void)> > command_dict;
//                                           ^^^^^^^^
//                               the signature of your commands. probably should have an error code.

void dir() { 
    std::cout << "dir" << std::endl; 
}
void help() { 
    std::cout << "help" << std::endl; 
}
void vol() {
    std::cout << "vol" << std::endl; 
}
void path() {
    std::cout << "path" << std::endl;
}
void tasklist() {
    std::cout << "tasklist" << std::endl;
}
void notepad() {
    std::cout << "notepad" << std::endl;
}
void echo() {
    std::cout << "echo" << std::endl;
}
void color() {
    std::cout << "color" << std::endl;
}
void ping() {
    std::cout << "ping" << std::endl;
}

int main() {
    std::cout << "Welcome to myShell!" << std::endl << "==>";
    command_dict c;
    c["dir"] = &dir;
    c["help"] = &help;
    c["vol"] = &vol;
    c["path"] = &path;
    c["tasklist"] = &tasklist;
    c["notepad"] = &notepad;
    c["echo"] = &echo;
    c["color"] = &color;
    c["ping"] = &ping;

    std::string input;
    while (std::getline(std::cin, input)) { // quit the program with ctrl-d
        auto it = c.find(input);
        if (it != end(c)) {
            (it->second)(); // execute the command
        }
        else {
            std::cout << "command \"" << input << "\" not known" << std::endl;
        }
    }
}