#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void findSum(vector<int>& candidates, int target, int n, int sum, vector<int> v, vector<vector<int>>& ret){
		if(sum == target) ret.push_back(v);
		if(sum > target || n >= candidates.size()) return;	
		findSum(candidates, target, n+1, sum, v, ret);
		v.push_back(candidates[n]);
		findSum(candidates, target, n+1, sum + candidates[n], v, ret);
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> v;
		vector<vector<int>> ans;
		findSum(candidates, target, 0, 0, v, ans);
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		return ans;
    }
};

int main(){
	Solution s;
	string line1;
	while(getline(cin, line1)){
		int n;
		vector<int> v;
		replace(line1.begin(), line1.end(), ',', ' ');
		istringstream is(line1);
		while(is >> n)
			v.push_back(n);
		
		string line2;
		getline(cin, line2);
		int target = stoi(line2);

		vector<vector<int>> ans = s.combinationSum2(v, target);
		for(auto i : ans){
			for(auto j : i)
				cout << j << " ";
			cout << endl;
		}
	}
}
