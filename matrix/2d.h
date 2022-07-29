#include <iostream>
using namespace std;
#pragma once
class matrix {
private:
	int **arr;
	int row;
	int col;
public:
	matrix(int, int);
	//~matrix();
	int &operator[](int);
	friend ostream &operator <<(ostream &, const matrix &);
	friend istream &operator >>(istream &, matrix &);
	matrix operator +(matrix &m);
	matrix operator -(matrix &m);
	matrix operator *(matrix &m);
	matrix &operator +=(matrix &m);
	matrix &operator -=(matrix &m);
	int &operator()(int, int);




};