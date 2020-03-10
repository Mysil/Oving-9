#include <iostream> 
#include "Dynamiskminne.h"
#include "Matrix.h"
#include "Dummy.h"

using namespace std; 


int main()
{	

	Matrix A{4,6};
	Matrix B{4};
	Matrix C{};

	cout << A << endl << A.getRows() << " " << A.getColumns() << " " << A.isValid() << " " << endl << endl
		 << B << endl << B.getRows() << " " << B.getColumns() << " " << B.isValid() << " " << endl << endl
		 << C << endl << endl << C.getRows() << " " << C.getColumns() << " " << C.isValid() << " " << endl << endl;

	Matrix D{A};
	Matrix E{};
	E=B; 

	cout << D << endl << D.getRows() << " " << D.getColumns() << " " << D.isValid() << " " << endl << endl
		 << E << endl << E.getRows() << " " << E.getColumns() << " " << E.isValid() << " " << endl << endl;

	Matrix A_5{2};
	A_5.set(0,0,1.0);
	A_5.set(0,1,2.0);
	A_5.set(1,0,3.0);
	A_5.set(1,1,4.0);

	Matrix B_5{2};
	B_5.set(0,0,4.0);
	B_5.set(0,1,3.0);
	B_5.set(1,0,2.0);
	B_5.set(1,1,1.0);

	Matrix C_5{2};
	C_5.set(0,0,1.0);
	C_5.set(0,1,3.0);
	C_5.set(1,0,1.5);
	C_5.set(1,1,2.0);

	A_5 += B_5 + C_5;
	
	cout << A_5;

	cin.get();
}














