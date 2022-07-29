#include "2d.h"
#include "iomanip"
matrix::matrix(int r, int c)
{
	row = r;
	col = c;
	arr = new int*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = '\0';
		}
	}
}

//subscript overload

int & matrix :: operator [](int i) {
	return *arr[i];
}

// extraction overload

ostream & operator<<(ostream &out, const matrix &d)
{
	for (int i = 0; i < d.row; i++) {
		for (int j = 0; j < d.col; j++) {
			out <<setw(5)<< d.arr[i][j] << "  ";
		}
		out << endl;
	}
	return out;
}

// insertion overload

istream & operator>>(istream &in,  matrix &c)
{
	for (int i = 0; i < c.row; i++) {
		cout << "Enter element at [" << i << "] Row " << endl;

		for (int j = 0; j < c.col; j++) {
			in >> c.arr[i][j] ;
		}
	}
	return in;
}
//overloading + operator
matrix matrix :: operator +(matrix &m) {
	matrix temp(m.row, m.col);
	if (row == m.row && col == m.col) {
		for (int i = 0; i < m.row; i++) {
			for (int j = 0; j < m.col; j++) {
				temp.arr[i][j] = arr[i][j] + m.arr[i][j];
			}
		}
		return temp;
	}
	else {
		cout << "/Given matrix cant be added";
	}
}
//overloading - operator
matrix matrix :: operator -(matrix &m) {
	if (row == m.row && col == m.col) {

		matrix temp(m.row, m.col);
		for (int i = 0; i < m.row; i++) {
			for (int j = 0; j < m.col; j++) {
				temp.arr[i][j] = arr[i][j] - m.arr[i][j];
			}
		}
		return temp;
	}
	else {
		cout << "Cannot subtract !";
	}
}
//overloading * operator
matrix matrix :: operator *(matrix &m) {
	if (this->col != m.row)
	{
		cout << "!Matrix donot satisfy multiplication" << endl;
	}
	else {
		matrix temp(m.row, m.col);
		for (int i = 0; i < m.row; i++) {
			for (int j = 0; j < m.col; j++) {
				temp.arr[i][j] = arr[i][j] * m.arr[i][j];
			}
		}
		return temp;
	}
}
//overloading += operator
matrix & matrix :: operator +=(matrix &m) {
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			arr[i][j] += m.arr[i][j];
		}
	}
	return *this;
}
//overloading -= operator
matrix & matrix :: operator -=(matrix &m) {
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			arr[i][j] -= m.arr[i][j];
		}
	}
	return *this;
}
//overloading parenthesis operator
int& matrix:: operator ()(int c, int r) {
	return arr[c][r];
}
//destructor
/*matrix::~matrix() {
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	cout << "\nDestructor called Successfully\n";
}*/
