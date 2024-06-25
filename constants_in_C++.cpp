#include <iostream>

int main()
{
	int a = 42; 
	const int * pa = &a;			// pA is a pointer to a constant int.
	std::cout << "Before: " << *pa << std::endl;
	//*pa = 5;						// error! trying to modify via a ptr to readonly.
	a = 41;						 	// assigning to *pa fails, but assigning to a is fine.   
	std::cout << "pa = : " << std::hex << pa << std::endl;
	pa++;							// pa is a ptr to const, but not const itself
	std::cout << "pa = : " << std::hex << pa << std::endl;
	std::cout << "After: " << *pa << std::endl;
	return 0;
}
