/*************************************************************************
    > File Name: test_vector.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 04 Feb 2017 03:14:05 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v1{1, 2, 3};
	cout << "v1 size: " << v1.size() << endl;

	vector<string> v2{10};
	cout << "v2 size: " << v2.size() << endl;

	vector<string> v3{10, "hi"};
	cout << "v3 size " << v3.size() << endl;

	for (auto it = v1.cbegin();
		 it != v1.cend();
		 it++) {
		cout << *it << endl;
	}
	return 0;
}
