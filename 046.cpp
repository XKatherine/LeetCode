#include<vector>
#include<iostream>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
	void helper(queue<int>& res, vector<int>& v, vector<vector<int>>& ret){
		int resLen = res.size();
		if(resLen == 0){
			ret.push_back(v);
			return;
		}

		for(int i = 0; i < resLen; ++i){
			int e = res.front();
			v.push_back(e);
			res.pop();
			helper(res, v, ret);
			v.pop_back();
			res.push(e);
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
		vector<int> v;
		vector<vector<int>> ret;
		queue<int> q;
		
		if(nums.size() == 0) return ret;

		for(auto i : nums) q.push(i);
		helper(q, v, ret);
		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line, ']')){
		line = line.substr(1);
		replace(line.begin(), line.end(), ',', ' ');
		istringstream is(line);

		int n;
		vector<int> v;
		while(is >> n) v.push_back(n);

		vector<vector<int>> ans = s.permute(v);
		for(auto i : ans){
			for(auto j : i)
				cout << j << ", ";
			cout << endl;
		}
	}
}
