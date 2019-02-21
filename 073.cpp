#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		if(matrix.size() == 0) return;
		vector<int> col(matrix[0].size(), 1);
		for(int i = 0; i < matrix.size(); i++){
			bool hasZero = false;
			for(int j = 0; j < matrix[0].size(); j++)
				if(matrix[i][j] == 0){
					col[j] = 0;
					hasZero = true;
				}
			if(hasZero)
				matrix[i] = vector<int>(matrix[0].size(), 0);
		}

		for(int i = 0; i < matrix[0].size(); i++)
			if(col[i] == 0)
				for(int j = 0; j < matrix.size(); j++)
					matrix[j][i] = 0;
	}
};

int main(){
	Solution s;
	string line;
	vector<vector<int>> m;
	getline(cin, line);
	getline(cin, line);
	while(line != "]"){
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ',', ' ');

		istringstream is(line);
		vector<int> v;
		int n;
		while(is >> n) v.push_back(n);

		m.push_back(v);
		getline(cin, line);
	}
	
	s.setZeroes( m );
	for(auto i : m){
		for(auto j : i)
			cout<<j<<" ";
		cout<<endl;
	}
}
