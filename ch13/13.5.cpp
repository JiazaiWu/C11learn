/*************************************************************************
    > File Name: 13.5.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Tue 23 May 2017 04:26:45 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Hasptr {
public:
	Hasptr(const string &s = string()):
		ps(new string(s)), i(0) {}

	Hasptr(const Hasptr &h) {
		cout << "copy init" << endl;
		i = h.i;
		ps = new string(*h.ps);
		cout << "i: " << i << " ps " << *ps << endl;
	}
private:
	string *ps;
	int i;
};

int main()
{
	Hasptr m_ptr("try");
	cout << "it will call copy init" << endl;
	Hasptr n_ptr = m_ptr;
	return 0;
}
