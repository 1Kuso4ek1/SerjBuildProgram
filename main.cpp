#include <iostream>
#include <cstdlib>
#include <string>

void help() {  
	std::cout << "Это меню помощи управления программой SERJ BUILD PROGRAMM. Ниже вы найдете команды программы. \n 1) help - помощь \n 2) assembly. Сразу после этой команды указать файл. Например: filename_programm.cpp - сборка программы  \n";  
}

bool find_comm(std::string com, int kolvo, char*argv[]) {
	for (int i = 0; i < kolvo; i++) {
		if (com == argv[i]) {
			return true;
		}
	}
	return false;
}

int main(int argc, char* argv[]) {
	std::string list_com[] = { "help", "assembly" };
	std::cout << "start program \n";
	if (argc == 1 || find_comm(list_com[0], argc, argv)) {
		help();
		exit(EXIT_SUCCESS);
	}
	if (find_comm(list_com[1], argc, argv) && argc > 2) { 
		std::string com = argv[2];
		std::string out = "g++ " + com + " -o test";
		system (out.c_str());    
		system ("./test");                                   
		std::cout << "\n Vozvrat: "  << "\n";
	}
	std::cout << "\033[32mCompilation finished!\033[0m" << std::endl;
	return 0;
}
