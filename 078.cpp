#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
	void subsets_(vector<int>& nums, int i, vector<int>& v, vector<vector<int>>& ret){
		if(i == nums.size()){
			ret.push_back(v);
			return;
		}

		subsets_(nums, i+1, v, ret);
		v.push_back(nums[i]);
		subsets_(nums, i+1, v, ret);
		v.pop_back();
	}
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret;
		if(nums.size() == 0) return ret;

		vector<int> v;

		subsets_(nums, 0, v, ret);

		return ret;
    }
};
int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ',', ' ');

		istringstream is(line);
		vector<int> v;
		int n;
		while(is >> n) v.push_back(n);

		vector<vector<int>> ans = s.subsets(v);

		for(auto i : ans){
			for(auto j : i)
				cout<<j<<" ";
			cout<<endl;
		}
	}
}
