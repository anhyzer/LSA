/*
 * author: Ryan Zimmerman
 * course: CPSC 2108 - Data Structures - Spring 2021
 * instructor: Dr. Alfredo Perez
 * campus: Columbus State University - TSYS School of Computer Science
*/

#ifndef INPUTCOLLECTION_H
#define INPUTCOLLECTION_H

#include <iostream>

class InputCollection {
	public:
		char UserInput(){

			bool validInput = true;
			char legalInputs[26];
			for(int i=0;i<26;i++){
				legalInputs[i] = (char)(i+65);
			}

			char input;
			std::cout<<"Enter a capital letter from the English alphabet: "<<std::endl;
			std::cin>>input;

			for(int i=0;i<26;i++){
				if(input != legalInputs[i]){
					validInput = false;
				}else{
					return input;
				}
			}while(!validInput){
					std::cout<<"Invalid input!"<<std::endl;				
					std::cout<<"Enter a capital letter from the English alphabet: "<<std::endl;
					std::cin>>input;
				for(int i=0;i<26;i++){
					if(input != legalInputs[i]){
					validInput = false;
					}else{
						return input;
					}
				}
			}
			return input;	
		}
};

#endif
