/*************************************************************************
    > File Name: 9.14.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Fri 19 May 2017 10:53:17 AM CST
 ************************************************************************/

#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main()
{
	list<char *> mlist = {"wu", "jia", "zai"};
	vector<string> mvector(3);
	int n = 0;

	for (list<char *>::iterator i = mlist.begin();
		 i != mlist.end();
		 i++) {
		mvector[n] = *i;
		n++;
    }

	for (const auto &item: mvector)
		cout << item << " " << endl;
	return 0;
}
