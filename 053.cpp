#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray_(vector<int>& nums, int left, int right, int& maxi) {
		if (left == right) return INT_MIN;
		if (left == right - 1) return nums[left];

		int prev = maxSubArray_(nums, left, (left + right)/2, maxi);
		int last = maxSubArray_(nums, (left + right)/2, right, maxi);

		if(prev >= 0)
		   	last += prev;
		
		maxi = max(maxi, last);
		return last;
	}

    int maxSubArray(vector<int>& nums) {
		if(nums.size() == 1) return nums[0];
		int maxi = INT_MIN;
		
		maxSubArray_(nums, 0, nums.size(), maxi);

		return maxi;

		/*
		int last = nums[0];
		int maxi = nums[0];
		for(int i = 1; i < nums.size(); i++){
			if (last >=0) last += nums[i];
			else last = nums[i];
			maxi = max(maxi, last);
		}
		return maxi;
		*/
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ']', ' ');

		istringstream is(line);
		int n;
		vector<int> v;

		while(is >> n) v.push_back(n);

		cout << s.maxSubArray(v) << endl;
	}
}
