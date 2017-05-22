/*************************************************************************
    > File Name: 10.3.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Fri 19 May 2017 02:37:42 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> int_v = {1,0,2,0,0,1,4};

	int sum = accumulate(int_v.cbegin(), int_v.cend(), 0);

	cout << "sum: " << sum << endl;

	return 0;
}
