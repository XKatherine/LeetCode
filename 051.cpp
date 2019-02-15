#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
	void helper(int cur, vector<int>& colNum, vector<int>& slash, vector<int>& backS, vector<vector<int>>& ret){
		int n = colNums.size();
		if(cur == n){
			ret.push_back(colNum);
			return;
		}

		for(int i = 0; i < n; ++i){
			if(colNum[i] >= 0) continue;
			if(slash[i+cur] >= 0) continue;
			if(backS[n-1-cur+i] >= 0) continue;

			colNum[i] = cur;
			slash[i+cur] = 1;
			backS[n-1-cur+i] = 1;
			helper(cur+1, colNum, slash, backS, ret);
			colNum[i] = -1;
			slash[i+cur] = -1;
			backS[n-1-cur+i] = -1;
		}
	}

    vector<vector<string>> solveNQueens(int n) {
		vector<int> colNum(n, -1);
		vector<int> slash(2*n - 1, -1);
		vector<int> backS(2*n - 1, -1);
		vector<vector<int>> ret;
		vector<vector<string>> ans;

		helper(0, colNum, slash, backS, ret); 

		for(auto i : ret){
			vector<string> sol;
			for(auto col : i){
				string s(n, '.');
				s.replace(col, 1, "Q");
				sol.push_back(s);
			}
			ans.push_back(sol);
		}

		return ans;
    }
};

int main(){
	Solution s;
	int n;
	while(cin >> n){
		vector<vector<string>> ans = s.solveNQueens(n);

		for(auto i : ans){
			for(auto j : i)
				cout << j << endl;
			cout << endl;
		}
	}
}
