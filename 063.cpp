#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
	/*
    void uniquePathsWithObstacles_(vector<vector<int>>& obstacleGrid, int m, int n, int pos_m, int pos_n, int& cnt) {
		if(obstacleGrid[pos_n][pos_m] == 1) return;
		if(pos_m == m-1 && pos_n == n-1) {
			++cnt;
			return;
		}

		if(pos_m+1<m) uniquePathsWithObstacles_(obstacleGrid, m, n, pos_m+1, pos_n, cnt);
		if(pos_n+1<n) uniquePathsWithObstacles_(obstacleGrid, m, n, pos_m, pos_n+1, cnt);

		return;
	}
	*/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int n = obstacleGrid.size();
		if(n == 0) return 0;
		int m = obstacleGrid[0].size();

		vector<vector<int>> d(n+1, vector<int>(m+1, 0));
		if(obstacleGrid[n-1][m-1] == 1 || obstacleGrid[0][0] == 1) return 0;
		d[1][1] = 1;

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++){
				if(i == 1 && j == 1) continue;
				if(obstacleGrid[n - i][m - j] == 0)
					if(d[i-1][j] + d[i][j-1]<INT_MAX)
						d[i][j] = d[i-1][j] + d[i][j-1];
			}

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

	cout<<s.uniquePathsWithObstacles(vec)<<endl;
}
