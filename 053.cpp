#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		if(nums.size() == 1) return nums[0];

		int last = nums[0];
		int maxi = nums[0];
		for(int i = 1; i < nums.size(); i++){
			/*
			if(last >= 0 && nums[i] >= 0){
				last += nums[i];
				maxi = max(maxi, last);
			}else if(last <0 && nums[i] >= 0){
				last = nums[i];
				maxi = max(maxi, last);
			}else if(last >=0 && nums[i] < 0){
				last += nums[i];
			}else if(last < 0 && nums[i] < 0){
				last = nums[i];
				maxi = max(maxi, last);
			}
			*/
			if (last >=0) last += nums[i];
			else last = nums[i];
			maxi = max(maxi, last);
		}
		return maxi;
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
