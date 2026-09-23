#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "personAPI.h">


int main(){
	
	std::ifstream file("C:\\Proga\\Programming\\lab1\\input.txt");
	std::string line;
	
	while(std::getline(file,line))
	{
		std::string word;
		Person person;
		
		std::stringstream ss(line);
		ss >> person.name;
		ss >> person.surname;
		ss >> word;
		person.birthyear = std::stoi(word);
		
		std::cout << person.name << " " << person.surname << " " << person.birthyear << " " << getPersonCategory(person) << "\n";
	}
	
//	std::cout << "Hello, world!" << std::endl;
	return 0;
}