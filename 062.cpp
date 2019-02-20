#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
		if(m == 1 || n == 1) return 1;

		vector<vector<int>> d(n, vector<int>(m, 1));
		for(int i = 1; i < n; i++)
			for(int j = 1; j < m; j++)
				d[i][j] = d[i-1][j] + d[i][j-1];

		return d[n-1][m-1];
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		istringstream is(line);
		int m, n;
		is >> m >> n;

		cout<<s.uniquePaths(m,n)<<endl;
	}
}
