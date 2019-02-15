#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

class Solution {
public:
	void rotate1B1(vector<vector<int>>& matrix, int n) {
		int N = matrix.size();
		int l = N - 2*n;
		if (l <= 1) return;

		for(int i = n; i < n + l - 1; ++i){
			int row = n;
			int col = i;
			int last = matrix[row][col];
			for(int k = 0; k < 3; ++k){
				int t = matrix[col][N-1-row];
				matrix[col][N-1-row] = last;
				last = t;
				int temp = row;
				row = col;
				col = N-1-temp;
			}
			matrix[col][N-1-row] = last;
		}
		rotate1B1(matrix, n + 1);
	}

    void rotate(vector<vector<int>>& matrix) {
		rotate1B1(matrix, 0);
    }
};

int main(){
	Solution s;
	vector<vector<int>> ans;

	string str;
	getline(cin, str);
	string line;
	getline(cin, line);
	while(line != "]"){
		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ']', ' ');

		int n;
		vector<int> v;
		istringstream is(line);
		while(is >> n) v.push_back(n);
		ans.push_back(v);

		getline(cin, line);
	}

	s.rotate(ans);
	for(auto i : ans){
		for(auto j : i)
			cout << j << " ";
		cout<<endl;
	}
}
