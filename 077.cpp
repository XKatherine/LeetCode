#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	void combine_(int n, int k, int i, vector<int>& v, vector<vector<int>>& ret){
		int size = v.size();
		if(size == k){
			ret.push_back(v);
			return;
		}

		for(int j = i; j <= n-(k-size)+1; ++j){
			v.push_back(j);
			combine_(n, k, j+1, v, ret);
			v.pop_back();
		}
	}

    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ret;
		if(k > n || n == 0 || k == 0) return ret;

		vector<int> v;
		combine_(n, k, 1, v, ret);

		return ret;
    }
};

int main(){
	Solution s;
	int n;
	while(cin >> n){
		int k;
		cin >> k;

		vector<vector<int>> ans = s.combine(n,k);
		for(auto i : ans){
			for(auto j : i)
				cout << j << " ";
			cout << endl;
		}
	}
}
