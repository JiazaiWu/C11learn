/*************************************************************************
    > File Name: move_construct.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Thu 08 Jun 2017 11:01:06 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int temp = 10;

class MyString
{
public:
	MyString()
	{
		a = nullptr;
		str = "default";
		index = -1;
	}

	MyString(int *b, const string &s, int ind):
		a(b),
		str(s),
		index(ind)
	{
		cout << "*a: " << *a << " str: " << str << " index: " << index << endl;
		cout << "addr str: " << &str << endl;
		cout << "this is construct" << endl;
	}

	MyString(MyString &&ms):
		a(ms.a),
		str(ms.str),
		index(ms.index)
	{
		ms.a = nullptr;
		cout << "*a: " << *a << " str: " << str << " index: " << index << endl;
		cout << "this is copy construct" << endl;
		cout << "addr str: " << &str << endl;
	}

	MyString& operator=(MyString &&ms)
	{
		a = ms.a;
		str = ms.str;
		index = ms.index;
		ms.a = nullptr;
		cout << "*a: " << *a << " str: " << str << " index: " << index << endl;
		cout << "copy operator" << endl;
		cout << "addr str: " << &str << endl;
	}

	~MyString()
	{
		cout << "decontruct" << endl;
	}
private:
	int *a;
	string str;
	int index;
};

MyString GetString()
{
	return MyString(&temp, "jiazai", 10);
}

int main()
{
	//MyString ms(&temp, "jiazai", 10);

	MyString ms1;
	
	ms1 = GetString();

	cout << "copy cons ???" << endl;
	MyString ms2(std::move(GetString()));
	return 0;
}
