#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
		vector<int> ans{-1,-1};
		int size = nums.size();
		if(size==0) return ans;

		int l,f;
		int left=0, right = size;
		while(left<right){
			int mid = (left+right)/2;
			if(nums[mid]<target)
				left = mid + 1;
			else if(nums[mid]>target)
				right = mid;
			else{
				int l = mid-1,r = mid+1;
				for(;l>=0&&nums[l]==target;--l);
				for(;r<size&&nums[r]==target;++r);
				ans[0] = l+1;
				ans[1] = r-1;
				break;
			}
    	}
		return ans;
	}
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		int n, target;
		vector<int> v;
		string str = "";
		for(auto i : line)
			str += i==','?' ':i;
		istringstream is(str);

		cin>>target;

		while(is>>n) v.push_back(n);
		vector<int> ret = s.searchRange(v,target);
		for(auto i : ret)
			cout<<i<<",";
		cout<<endl;
	}
}
