#include "Dummy.h"
#include "iostream"

Dummy::Dummy() {
    //lager en ny minneplassering med verdi 0
    num = new int{0};
}
Dummy::~Dummy() {
    //sletter den eneste reserverte minneplasseringen
    delete num;
}
void Dummy::operator =(const Dummy &dumbdumb){
    //lager først en ny minneplassering før jeg så kopierer verdien
    num = new int{0};
    *num = *dumbdumb.num;
}

Dummy::Dummy(const Dummy& dumbdumb){
    //lager først en ny minneplassering før jeg så kopierer verdien
    num = new int{0};
    *num = *dumbdumb.num;
}
//hentet direkte fra oppgavebeskrivelsen
void dummyTest() { 
	Dummy a;
	*a.num = 4;
	Dummy b{a};
	Dummy c;
	c=a;
	std::cout << "a:"<< *a.num << std::endl;
    std::cout << "b:"<< *b.num << std::endl;
    std::cout << "c:"<< *c.num << std::endl;
	*b.num = 3; 
	*c.num = 5;
    std::cout << "a:"<< *a.num << std::endl;
    std::cout << "b:"<< *b.num << std::endl;
    std::cout << "c:"<< *c.num << std::endl;
	std::cin.get();
}
		
