#include<iostream>
#include<sstream>
#include<vector>
#include<string>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
		int current = 0;
		for(int i=0; i<nums.size(); i++){
			if(nums[i]!=val){
				nums[current] = nums[i];
				current++;
			}
		}
		return current;
	}
	
	/*
    int removeElement(std::vector<int>& nums, int val) {
		int cnt = 0;
		for(int i=0; i<nums.size(); i++){
			if(nums[i]==val){
				nums.erase(nums.begin()+i);
				i--;
			}
		}
		return nums.size();
    }
	*/
};

int main(){
	Solution s;
	std::string line;
	while(std::getline(std::cin,line)){
		int val, data;
		std::vector<int> v;
		std::istringstream is(line);
		std::cin>>val;
		while(is>>data){
			v.push_back(data);
			if(is.peek()==',')
				is.ignore();
		}
		std::cout<<s.removeElement(v, val)<<std::endl;
		for(auto i : v)
			std::cout<<i<<" ";
		std::cout<<std::endl;
	}
}
