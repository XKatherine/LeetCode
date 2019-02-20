#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		if(m == 0 || n == 0) return 0;

		long d[n+1][m+1];
		//memset(d[0], LONG_MAX, sizeof(long)*(n+1)*(m+1));
		for(int i = 0; i <= n; i++)
			d[i][0] = LONG_MAX;
		for(int i = 2; i <= m; i++)
			d[0][i] = LONG_MAX;
		d[0][1] = 0;

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				d[i][j] = grid[i-1][j-1] + min(d[i-1][j], d[i][j-1]);

		return d[n][m];
		
    }
};

int main(){
	Solution s;
	string line;
	vector<vector<int>> vec;
	getline(cin, line);
	getline(cin, line);
	while(line != "]"){
		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), '[', ' ');

		istringstream is(line);
		vector<int> v;
		int n;
		while(is >> n) v.push_back(n);

		vec.push_back(v);
		getline(cin, line);
	}

	cout<<s.minPathSum(vec)<<endl;
}
