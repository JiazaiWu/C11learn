/*************************************************************************
    > File Name: test.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Tue 16 May 2017 02:42:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};
	const char *cp = ca;
	while (*cp) {
		cout << *cp << endl;
		++cp;
	}
	return 0;
}
