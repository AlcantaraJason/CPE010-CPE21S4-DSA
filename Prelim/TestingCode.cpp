#include <iostream>
#include "stack.h"

int main(){
	stack <int> s1;	
	
	for(int i = 1; i <= 10; i++){
		s1.push(i);
		}
		
	//isEmpty
	std::cout<<"Testing isEmpty: /n";
	std::cout<<s1.isEmpty()<<std::endl<<std::endl;	
		
		
	
	//push
	std::cout<<"Testing Push: /n";
	for(int i = 1; i <= 10; i++){
		s1.push(i);
	}
	
	//stack overflow check
	s1.push(100);
	
	//pop
	std::cout<<std::endl;
	std::cout<<"Testing pop: /n";
	s1.pop();
	
	//Display
		std::cout<<std::endl;
	std::cout<<"Testing Display: /n";
	s1.display();
	
	//Peek
		std::cout<<std::endl;
	std::cout<<"Testing peek: /n";
	s1.peek();
	
	
	return 0;
}
