/*************************************************************************
    > File Name: lam.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Fri 19 May 2017 02:53:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	auto func1= [a]{cout << "a: " << a << endl;};
	func1();
	a = 20;
	cout << "a changed to 20" << endl;
	func1();

	int b = 10;
	auto func2 = [&b]{cout << "b: " << b << endl;};
	func2();
	b = 20;
	cout << "b changed to 20" << endl;
	func2();

	int c = 10;
	auto func3 = [c]{int temp = c;cout << "temp: " << temp << endl;temp++;};
	func3();
	func3();
	return 0;
}
