#include<iostream>
#include<vector>
#include<string>
#include<sstream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
		if(nums.size()<=1) return nums.size();
		int i = 1;
		while(i<nums.size()){
			if(nums[i]==nums[i-1]){
				int start = i;
				while(i+1<nums.size()&&nums[i]==nums[i+1]) i++;
				int end = i+1;
				nums.erase(nums.begin()+start,nums.begin()+end);
				i = start;
			}else
				i++;
		}
		return nums.size();
    }
};

int main(){
	Solution s;
	std::string line;
	while(std::getline(std::cin, line)){
		std::istringstream is(line);
		int n;
		std::vector<int> v; 
		while(is>>n){
			v.push_back(n);
			if(is.peek()==',')
				is.ignore();
		}
		std::cout<<s.removeDuplicates(v)<<std::endl;
		for(auto i : v)
			std::cout<<i<<" ";
	}
}
