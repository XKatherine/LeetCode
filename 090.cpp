#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ret{vector<int>{}};
		if(nums.size() == 0) return ret;

		sort(nums.begin(), nums.end());

		int prev = ret.size();
		for(int i = 0; i < nums.size(); ++i){
			int size = ret.size();
			if(i > 0 && nums[i-1] != nums[i])
				prev = size;
			for(int j = prev; j > 0; --j){
				vector<int> v = ret[size-j];
				v.push_back(nums[i]);
				ret.push_back(v);
			}
		}
		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), ',', ' ');

		istringstream is(line);
		vector<int> v;
		int n;
		while(is >> n) v.push_back(n);

		vector<vector<int>> ans = s.subsetsWithDup(v);

		for(auto i : ans){
			for(auto j : i)
				cout<< j <<" ";
			cout<<endl;
		}
	}
}
