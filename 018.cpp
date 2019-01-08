#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		sort(nums.begin(),nums.end());
		for(int i=0,N = nums.size(); i<N-3;){
			for(int n=N-1;n>i+2;){
				for(int j=i+1,m=n-1;m>j;){
					int res = nums[i]+nums[j]+nums[m]+nums[n];
					if(res>target){
						do{m--;}while(nums[m+1]==nums[m]);
					}else if(res<target){
						do{j++;}while(nums[j-1]==nums[j]);
					}else{
						ans.push_back(vector<int>{nums[i],nums[j],nums[m],nums[n]});
						do{m--;}while(nums[m+1]==nums[m]);
						do{j++;}while(nums[j-1]==nums[j]);
					}
				}
				do{n--;}while(nums[n+1]==nums[n]);
			}
			do{i++;}while(nums[i-1]==nums[i]);
		}
		return ans;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		istringstream is(line);
		vector<int> nums;
		int target, n;
		cin>>target;
		while(is>>n){
			nums.push_back(n);
			if(is.peek()==',')
				is.ignore();
		}
		vector<vector<int>> v = s.fourSum(nums, target);
		for(int i=0; i<v.size(); i++)
			cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<" "<<v[i][3]<<" "<<endl;
	}
}
