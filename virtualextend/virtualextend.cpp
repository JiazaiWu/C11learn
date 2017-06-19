/*************************************************************************
    > File Name: virtualextend.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Mon 19 Jun 2017 02:42:57 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class base
{
public:

	base()
	{
		cout << "base empty" << endl;
	}

	base(const base &obj)
	{
		cout << "base copy" << endl;
	}

	void show()
	{
		cout << "this is base!" << endl;
	}
};

class extend: public /*virtual*/ base // if virtual unmarked it will bb
{
public:
	extend()
	{
		cout << "extend empty" << endl;
	}
	
	extend(const extend &obj)
	{
		cout << "extend copy" << endl;
	}

	extend(const extend* obj)
	{
		cout << "sp copy" << endl;
	}

	void show()
	{
		cout << "this is extend1" << endl;
	}
};


int main()
{
	base b;
	extend e(static_cast<extend*>(&b));
	e.show();
	return 0;
}
