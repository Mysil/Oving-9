#include <iostream> 
#include "Dynamiskminne.h"
#include "Matrix.h"
#include "Dummy.h"

using namespace std; 


int main()
{	

	//CreateFibonacci(); 
	
	//testMatrixClass();

	//dummyTest(); 

	Matrix A{7};
	Matrix B{};

	B = A; 

	cout << B; 

	

	
	
	cin.get();
}














