/*************************************************************************
    > File Name: lam.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Mon 28 Nov 2016 02:38:17 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
	

	int a = 10;
	string str = "jiazai";

	//1
	int b = [a](int x) -> int {return a+x;}(5);
	cout << "b: " << b << endl;

	//2, the marked sentence will makesegmentation fauly
	auto func = [str](const string &s)/*->string*/{cout << str + s << endl;};
	func(" say hello");

	return 0;
}
