/*************************************************************************
    > File Name: 12.6.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Mon 22 May 2017 03:27:42 PM CST
 ************************************************************************/

#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;

shared_ptr<vector<int>> v_factory()
{
	return make_shared<vector<int>>();
}

int main()
{
	auto mptr = v_factory();
	int n;
	while (cin >> n)
		mptr->push_back(n);

	cout << "sizeof " << sizeof(mptr) << endl;
	for_each(mptr->begin(), mptr->end(), [](const int &i){cout << i << " ";});
	return 0;
}
