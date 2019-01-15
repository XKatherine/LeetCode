#include<iostream>
#include<vector>
#include<string>
#include<sstream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
		int size = nums.size();
		if(size == 0) return -1;
		if(size == 1) return nums[0]==target?0:-1;
		int left = 0, right = size, gap=size;
		while(left<right){
			int mid = (left+right)/2;
			if(nums[mid-1]>nums[mid]){
				gap = mid;
				break;
			}else if(nums[mid]>=nums[0])
				left = mid+1;
			else
				right = mid;
		}
		if(target>nums[0]){
			left = 0;
			right = gap;
		}else if(target<nums[0]){
			left = gap;
			right = size;
		}else return 0;
		while(left<right){
			int mid = (left+right)/2;
			if(nums[mid]>target){
				right = mid;
			}else if(nums[mid]<target)
				left = mid+1;
			else
				return mid;
		}
		return -1;
    }
};

int main(){
	Solution s;
	std::string line;
	while(std::getline(std::cin,line)){
		std::string str = "";
		for(auto i : line)
			str += i==','?' ':i;
		std::istringstream is(str);
		std::vector<int> nums;
		int target, n;
		while(is>>n)
			nums.push_back(n);
		std::cin>>target;
		std::cout<<s.search(nums,target)<<std::endl;
	}
}
