#include "2d.h"
int main() {

	matrix m1(3, 3);
	matrix m2(3, 3);
	//insertion operator
	cin >> m1;
	cin >> m2;
	//extraction 
	cout << "Matrix 1 is :" << endl;
	cout << m1;
	cout << "Matrix 2 is :" << endl;
	cout << m2;
	cout << "Element at position at index [2][1] using parenthesis operator  of first matrix :" << m1(2, 1) << endl;
	cout << "Addition + overloaded" << endl;
	cout << m1 + m2;
	cout << "Result by += operator" << endl;
	m1 += m2;
	cout << m1;
	cout << "subtraction - overloaded" << endl;
	cout << m1 - m2;
	
	cout << "Result by -= operator" << endl;

	m1 -= m2;
	cout << m1;
	cout << "Multiplication * overloaded" << endl;
	cout << m1 * m2;
	cout << "\nTrying [] it can access individual element\n";
	cout << m1[1];
}