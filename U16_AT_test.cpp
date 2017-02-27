/*************************************************************************
    > File Name: test.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Tue 08 Dec 2015 01:54:58 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#define uint16_t unsigned short
#define uint8_t unsigned char

uint16_t U16_AT(const uint8_t *ptr) {
	cout << ptr[0] << endl;
	cout << ptr[1] << endl;
	return ptr[0] << 8 | ptr[1];
}

int main()
{
	uint8_t ptr = 4;
	uint16_t res = U16_AT(&ptr);
	cout << res << endl;

	return 0;
}
