#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		for(int i = 0; i < len; i++){
			int n = nums[i];
			if(n <= 0 || n == i+1 || n > len || nums[i] == nums[n-1]) continue;
			swap(nums[i], nums[n-1]);
			--i;
//			if(i != len-1) --i;
		}
		for(int i = 0; i < len; i++)
			if(nums[i] != i+1)
				return i+1; 
		return len+1;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), ',', ' ');
		istringstream is(line);

		int n;
		vector<int> nums;
		while(is >> n)
			nums.push_back(n);

		cout<<s.firstMissingPositive(nums)<<endl;
	}
}
