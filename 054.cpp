#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> v;
		int H = matrix.size();
		if (H == 0) return v;
		if (H == 1) return matrix[0];
		int W = matrix[0].size();

		int cirNum = min((W+1)/2, (H+1)/2);

		for (int i = 0; i < cirNum; ++i) {
			for(int k = i; k <= W-i-1; ++k)
				v.push_back(matrix[i][k]);
			for(int k = i+1; k <= H-i-1; ++k)
				v.push_back(matrix[k][W-i-1]);
			if ( H-1-i > i)
				for(int k = W-i-2; k > i; --k)
					v.push_back(matrix[H-1-i][k]);
			if ( i < W-i-1)
				for(int k = H-i-1; k > i; --k)
					v.push_back(matrix[k][i]);
		}


		
		return v;
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

	vector<int> ret = s.spiralOrder(ans);
	for(auto i : ret)
		cout << i << " ";
	cout<<endl;
}
