#include <iostream>
#include "Q.h"


int main() {
	Queue <std::string> CPE21S4;
	
	CPE21S4.enqueue("Franciss");
	CPE21S4.enqueue("Jason!!!!");
	CPE21S4.enqueue("CURWIN");
	CPE21S4.enqueue("ABILA");
	CPE21S4.enqueue("Dano");
	CPE21S4.getFront();
	
	CPE21S4.dequeue();
	CPE21S4.getFront();
	CPE21S4.getrear();	
	CPE21S4.display();
	
	return 0;
}
