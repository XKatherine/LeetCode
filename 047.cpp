#include<vector>
#include<iostream>
#include<queue>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

class Solution {
public:
	void helper(queue<int>& res, vector<int>& v, vector<vector<int>>& ret){
		int resLen = res.size();
		if(resLen == 0){
			ret.push_back(v);
			return;
		}

		int e = res.front();
		v.push_back(e);
		res.pop();
		helper(res, v, ret);
		v.pop_back();
		res.push(e);
		int last = e;
		for(int i = 1; i < resLen; ++i){
			e = res.front();
			if(e == last){
				res.pop();
				res.push(e);
			}else{
				v.push_back(e);
				res.pop();
				helper(res, v, ret);
				v.pop_back();
				res.push(e);
			}
			last = e;
		}
	}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<int> v;
		vector<vector<int>> ret;
		queue<int> q;
		
		if(nums.size() == 0) return ret;

		sort(nums.begin(), nums.end());
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

		vector<vector<int>> ans = s.permuteUnique(v);
		for(auto i : ans){
			for(auto j : i)
				cout << j << ", ";
			cout << endl;
		}
	}
}
