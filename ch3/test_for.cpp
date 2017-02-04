/*************************************************************************
    > File Name: test_for.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 04 Feb 2017 02:40:55 PM CST
 ************************************************************************/

#include<iostream>
#include<cctype>

using namespace std;

int main() {
	string s("some string!!!");

	decltype(s.size()) punct_cnt = 0;

	for (auto c : s) {
		cout << c << endl;
		if (ispunct(c)) {
			cout << "It is punct" << endl;
			++punct_cnt;
		}
	}
	cout << punct_cnt
		 << " punctuation characters in " << s << endl;

	for (auto &c : s) {
		c = toupper(c);
	}
	cout << s << endl;

	const string con_str = "Keep out!!!";
	for (auto &c : con_str) {
		cout << c << endl;
		//c = "X";
	}
	return 0;
}
