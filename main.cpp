#include <iostream>
#include <cstdlib>
#include <clocale>
#include <string>

void help(){
  
  std::cout << "Это меню помощи управления программой SERJ BUILD PROGRAMM. Ниже вы найдете команды программы. \n 1) help - помощь \n 2) assembly. Сразу после этой команды указать файл. Например: filename_programm.cpp - сборка программы  \n";
  
}

int find_comm(std::string com, int kolvo, char*argv[]){
  int k = 0;
  for (int i = 0; i < kolvo; i++){
    if (com == argv[i]){
      k = 1;
      break;
    }
  }
  return k;
}


int main(int argc, char* argv[]){
  std::string list_com[] = {"help", "assembly"};
  setlocale(LC_ALL, "russian");
  std::cout << " start program \n";
  if (argc == 1){
    help();
    
  }
  if(argc >= 2){
    
    
    if (find_comm("help", argc, argv) == 1){
      
      help();
    }
    
    if (find_comm("assembly", argc, argv) == 1 && argc > 2){
      
      std::string com = argv[2];
      std::string out = "g++ " + com + " -o test";
      system (out.c_str());    
      system ("./test");                                   
      std::cout << "\n Vozvrat: "  << "\n";
    }
    
  }
	
 std::cout << "\033[32mCompilation finished!\033[0m" << std::endl;
  return 0;
	
	}
