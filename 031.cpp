#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<string>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
		int size = nums.size();
		if(size<=1) return;
		int larger = size-1;
		while(larger>0&&nums[larger-1]>=nums[larger]) --larger;
		if(larger==0){
			std::sort(nums.begin(),nums.end());
			return;
		}
		int i = size-1;
		for(;i>=larger&&nums[i]<=nums[larger-1];i--);
		int temp = nums[i];
		nums[i] = nums[larger-1];
		nums[larger-1] = temp;
		sort(nums.begin()+larger,nums.end());
    }
};

int main(){
	Solution s;
	std::string line;
	while(std::getline(std::cin,line)){
		std::string str = "";
		for(auto i:line)
			str += i==','?' ':i;
		std::istringstream is(str);
		std::vector<int> nums;
		int n;
		while(is>>n) nums.push_back(n);
		s.nextPermutation(nums);
		for(auto i:nums)
			std::cout<<i<<',';
		std::cout<<std::endl;
	}
}
