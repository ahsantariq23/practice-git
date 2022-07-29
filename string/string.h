#pragma once
#include<iostream>
using namespace std;
class String
{
private:
	char* str;
	int length;
public:
	String();
	~String();
	String(char*);
	String(int);
	char* getstr();
	friend ostream & operator <<(ostream& , String& );
	friend istream & operator >>(istream& in, String& d);
	bool operator<(String&);
	bool operator>(String&);
	bool operator==(String&);
	String& operator+(String& d);
	String operator=(String&);
	int& getlength(String&);
	char& operator[](int);
	String operator()(int x, int y)const;

};