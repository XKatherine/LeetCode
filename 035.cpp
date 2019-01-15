#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int size = nums.size();
		if(size==0||target<=nums[0]) return 0;
		if(size==1) return target<=nums[0]?0:1;
		if(target>nums[size-1]) return size;
		
		int left=0, right = size;
		while(left<right){
			int mid = (left+right)/2;
			if(nums[mid]>target&&nums[mid-1]>=target)
				right = mid;
			else if(nums[mid]<target&&nums[mid+1]<=target)
				left = mid+1;
			else if(nums[mid]>target&&nums[mid-1]<target)
				return mid;
			else if(nums[mid]<target&&nums[mid+1]>target)
				return mid+1;
			else
				return mid;
		}
		return size-1;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		string str = "";
		for(auto i : line)
			str += i==','?' ':i;
		istringstream is(str);

		vector<int> nums;
		int n, target;
		
		cin>>target;
		while(is>>n) nums.push_back(n);
		
		cout<<s.searchInsert(nums,target)<<endl;
	}
}
