#include<vector>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ret(n, vector<int>(n));

		int cnt = 0;
		for(int i = 0; i < (n+1)/2; ++i){
			for(int k = i; k < n - i; ++k)
				ret[i][k] = ++cnt;
			for(int k = i+1; k < n - i; ++k)
				ret[k][n-i-1] = ++cnt;
			for(int k = n-i-2; k > i; --k)
				ret[n-i-1][k] = ++cnt;
			for(int k = n-i-1; k > i; --k)
				ret[k][i] = ++cnt;
		}
		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		istringstream is(line);
		int n;
		is >>n;

		vector<vector<int>> ans = s.generateMatrix(n);

		for(auto i : ans){
			for(auto j : i)
				cout<<j;
			cout<<endl;
		}
	}
}
	
