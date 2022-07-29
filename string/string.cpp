#include<iostream>
#include"String.h"
using namespace std;
String::String()
{
	length = 0;
	str = nullptr;
}
String::~String()
{
	if (length)
	{
		delete[]str;
	}
}
String::String(char* s)
{
	int i = 0;
	for (i = 0; s[i] != '\0'; i++) {
	}
	length = i;
	str = new char[length + 1];
	for (i = 0; i < length; i++)
	{
		str[i] = s[i];
	}
	str[i] = '\0';
}
String::String(int a)
{
	length = a;
	str = new char[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = '\0';
	}
}
char* String::getstr()
{
	return str;
}
ostream &operator <<(ostream &out, String &d)
{
	for (int i = 0; i < d.length; i++)
	{
		out << d.str[i];
	}
	return out;
}
istream &operator >>(istream &in, String &d)
{
	int i = 0;
	cout << "Enter the size :";
	cin >> d.length;
	d.str = new char[d.length + 1];
	cout << "Enter the string :";
	for (i = 0; i < d.length; i++)
	{
		in >> d.str[i];
	}
	d.str[i] = '/0';
	return in;
}

bool String::operator<(String& d)
{
	int flag = 0, l = 0; bool val = false;
	for (int i = 0; str[i] != '\0'; i++)
	{
		flag = flag + str[i];
	}
	for (int i = 0; d.str[i] != '\0'; i++)
	{
		l = l + d.str[i];
	}
	if (flag < l)
	{
		val = true;
		return val;
	}
	else
	{
		val = false;
		return val;
	}
}
bool String::operator>(String& d)
{
	int flag = 0, lof = 0; bool count = false;
	for (int i = 0; str[i] != '\0'; i++)
	{
		flag = flag + str[i];
	}
	for (int i = 0; d.str[i] != '\0'; i++)
	{
		lof = lof + d.str[i];
	}
	if (flag > lof)
	{
		count = true;
		return count;
	}
	else
	{
		count = false;
		return count;
	}
}
bool String::operator==(String& d)
{
	int flag = 0, lof = 0; bool check = false;
	for (int i = 0; str[i] != '\0'; i++)
	{
		flag = flag + str[i];
	}
	for (int i = 0; d.str[i] != '\0'; i++)
	{
		lof = lof + d.str[i];
	}
	if (flag == lof)
	{
		check = true;
		return check;
	}
	else
	{
		check = false;
		return check;
	}
}
String& String::operator+(String& d)
{
	int l = d.length;
	int k = length;
	int count = 0;
	count = this->length + d.length;
	char* temparr = new char[count + 1];

	for (int i = 0; i < this->length; i++)
	{
		temparr[i] = str[i];
	}
	delete[]this->str;
	this->length = count;
	str = new char[this->length + 1];
	for (int i = 0; i < k; i++)
	{
		str[i] = temparr[i];
	}
	int my, y;
	for (my = length, y = 0; d.str[y] != '\0'; my++, y++)
	{
		str[my] = d.str[y];
	}
	return *this;
	

}
String String::operator=(String& n)
{
	if (this->length == n.length)
	{
		for (int i = 0; i < this->length; i++)
		{
			this->str[i] = n.str[i];
		}
	}
	else
	{
		delete[]this->str;
		this->length = 0;
		int k = 0, j = 0;
		for (int i = 0; n.str[i] != '\0'; i++) { k++; }
		length = k;
		this->str = new char[length + 1];
		cout << this->length << endl;
		for (j = 0; j < length; j++)
		{
			this->str[j] = n.str[j];
		}
	str[j] = '\0';
	}
	return *this;

}
int& String::getlength(String& d)
{
	return this->length;
}
char& String::operator[](int a)
{
	if (a<0 || a>this->length)
	{
		cout << "Invalid index number !" << endl;
	}
	else if (a > 0 && a <= this->length)
	{
		cout << str[a];
		return str[a];
	}
}
String String::operator()(int c, int o)const
{
	if (c < 0 || c >= this->length)
	{
		return String();
	}
	else
	{
		String tem(o);
		int j = 0;
		if (o = this->length - c)
		{
			for (int i = 0; i < o; i++)
			{
				tem[i] = this->str[i + c];
			}
		}
		else
		{
			for (int i = 0; i < this->length - c; i++)
			{
				tem[i] = this->str[i + c];
			}
			for (int i = this->length + c; i < o; i++)
			{
				tem[i] = 0;

			}
		}
		return tem;
	}
}