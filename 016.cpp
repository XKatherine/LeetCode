#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int mini = INT_MAX;
		int ans;
		sort(nums.begin(),nums.end());
		for(int i=0,N=nums.size();i<N;){ 
			for(int j=i+1,k=N-1;j<k;){ 
				if(abs(nums[i]+nums[j]+nums[k]-target) < mini){
					mini = abs(nums[i]+nums[j]+nums[k]-target);
					ans = nums[i]+nums[j]+nums[k];
				}
				if(nums[i]+nums[j]+nums[k] > target){
					do{ k--; }while(nums[k+1]==nums[k]);
				}else if(nums[i]+nums[j]+nums[k] < target){
					do{ j++; }while(nums[j-1]==nums[j]);
				}else{
					return target;
				}
			}
			do{ i++; }while(nums[i-1]==nums[i]);
		}
		return ans;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		istringstream is(line);
		vector<int> v;
		int target;
		int n;
		cin >> target;
		while(is>>n){
			v.push_back(n);
			if(is.peek()==',')
				is.ignore();
		}
		cout<<s.threeSumClosest(v, target);
	}
}
