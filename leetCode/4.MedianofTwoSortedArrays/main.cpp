/*************************************************************************
    > File Name: main.cpp
    > Author: jiazai_wu
    > Mail: wujiazaiwh@163.com 
    > Created Time: Thu 06 Jul 2017 01:36:03 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int findMedian(vector<int>& a, const int begin1, const int len1,
			       vector<int>& b, const int begin2, const int len2,
				   const int step) {
		if(len1 > len2){
			return findMedian(b, begin2, len2,
					   a, begin1, len1,
					   step);
		}
		if(len1 == 0) {
			return b[begin2+step-1];
		}
		if(step == 1)
			return min(a[begin1], b[begin2]);
		int part1 = min(len1, step/2);
		int part2 = step - part1;
		if (a[begin1+part1-1] == b[begin2+part2-1])
			return a[begin1+part1-1];
		else if (a[begin1+part1-1] < b[begin2+part2-1])
			return findMedian(a, begin1 + part1, len1 - part1,
					          b, begin2, len2,
							  step - part1);
		else
			return findMedian(a, begin1, len1,
					          b, begin2 + part2, len2 - part2,
							  step - part2);
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		cout <<"len1 " << len1 << " len2 " << len2 << endl;
		int begin1 = 0;
		int begin2 = 0;
		int sumlen = len1 + len2;
		if (sumlen&1) {
			//O(log m+n)
			return findMedian(nums1, begin1, len1,
						      nums2, begin2, len2,
							  sumlen/2 + 1);
		} else {
			//a lot more time
			//FIX ME
			return (findMedian(nums1, begin1, len1,
						       nums2, begin2, len2,
							   sumlen/2) + 
					findMedian(nums1, begin1, len1,
						       nums2, begin2, len2,
							   sumlen/2 + 1)       ) / 2.0;
		}
    }
};

int main()
{
	vector<int> a = {2};
	vector<int> b ;
	double ret = Solution().findMedianSortedArrays(a, b);
	cout << ret << endl;
	return 0;
}
