/*************************************************************************
    > File Name: test_getline.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 04 Feb 2017 11:10:03 AM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

int main() {
	string s = "jia""zai";

	cout << "cin()" <<endl;
	cin >> s;
	cout << "size of " << s << " is " << s.size() << endl;

	cout << "getline()" << endl;
	//if input "jiazai", size is 6, \r should be dropped
	while (getline(cin, s))
		cout << "size of " << s << " is " << s.size() << endl;

	auto len = s.size();
	cout << len << endl;
	return 0;
}
