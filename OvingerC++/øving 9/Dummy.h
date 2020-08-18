#include "iostream"
#pragma once

class Dummy { 
	public:
		int *num;
		Dummy();
		~Dummy();
        Dummy(const Dummy& dumbdumb);
        void operator =(const Dummy& dumbdumb);
};

void dummyTest();