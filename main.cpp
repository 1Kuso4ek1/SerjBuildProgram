#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void help() {  
	std::cout << "Это меню помощи управления программой SERJ BUILD PROGRAM. Ниже вы найдете команды программы. \n 1) help - помощь \n 2) assembly. Сразу после этой команды указать файл. Например: filename_programm.cpp - сборка программы  \n"; 
    exit(EXIT_SUCCESS);
}

void compile(std::string c) {
    std::ifstream fin("INSTRUCTION.txt");
    std::string tmp;
    while (getline(fin, tmp)) {
        system(tmp.c_str());
    }
    fin.close();
    system(std::string("g++ " + c + " -o test && ./test").c_str());
    std::cout << "\033[32mCompilation finished!\033[0m" << std::endl;
}

int main(int argc, char* argv[]) {
    std::cout << "\033[32mStart program\033[0m" << std::endl;
    if(argv[1] == nullptr) help();
	std::unordered_map<std::string, int> list_com = { { "help", 1 }, { "assembly", 2 } };
    switch(list_com[argv[1]])
    {
    case 1: help(); break;
    case 2: compile(argv[2]); break;
    default: help(); break;
    }
	return 0;
}
