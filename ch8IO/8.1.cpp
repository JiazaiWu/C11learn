/*************************************************************************
    > File Name: 8.1.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Thu 18 May 2017 05:47:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

istream& printfToEof(istream& s)
{
	string str;
	auto pstate = s.rdstate();
	while (s >> str)
	{
		if(s.eof() )
			break;
		cout << str;
	}

	s.setstate(pstate);

	return s;
}

int main()
{
	printfToEof(cin);

	return 0;
}
