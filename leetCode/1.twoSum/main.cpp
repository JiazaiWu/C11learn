/*************************************************************************
    > File Name: main.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Tue 04 Jul 2017 03:07:34 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		//store <value, index> in the nums
		unordered_map<int, int> hash;
		vector<int> ret;
		for (int n = 0; n < nums.size(); n++) {
			//attention  a+b=c --> b = c - a;
			int toFind = target - nums[n];
			if(hash.find(toFind) != hash.end()) {
				ret.push_back(n);
				ret.push_back(hash[toFind]);
				return ret;
			}
			hash[nums[n]] = n;
		}
		return ret;
    }
};

int main()
{
	vector<int> arg= {1,2,4};
	auto ret = (new Solution)->twoSum(arg, 6);
	cout << ret[0] << " " << ret[1] << endl;
}
