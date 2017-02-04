/*************************************************************************
    > File Name: test_array.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 04 Feb 2017 04:17:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
	int a1[] = {1 ,2, 3};
	//error: too many initializers for ‘int [3]’
	//decltype(a1) a2 = {1, 2, 3, 4};

	int *beg = begin(a1);
	int *last = end(a1);

	while (beg != last) {
		cout << *beg << endl;
		beg++;
	}
	return 0;
}
