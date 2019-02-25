#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		if(matrix.size() == 0) return 0;
		int ret = 0;

		for(int i = 0; i < matrix.size(); ++i){
			for(int j = 0; j < matrix[0].size(); ++j){
				int mini = matrix[0].size();
				for(int row = i; row < matrix.size() && matrix[row][j] == '1'; ++row){
					int col = j + 1;
					for(;col < matrix[0].size() && matrix[row][col] == '1' ; ++col);
					mini = min(mini, col);
					ret = max(ret, (mini - j)*(row - i + 1));
				}
			}
		}

		return ret;

    }
};

vector<vector<char>> getMatrix(){
	string line;
	getline(cin, line);
	vector<vector<char>> ret;
	while(line != "]"){
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), '\"', ' ');

		istringstream is(line);
		vector<char> v;
		char c;
		while(is >> c) v.push_back(c);
		ret.push_back(v);

		getline(cin,line);
	}

	return ret;
}

int main(){
	Solution s;
	string line;
	getline(cin,line);
	while(line == "["){
		vector<vector<char>> matrix =  getMatrix();

		cout<<s.maximalRectangle(matrix)<<endl;
		
		getline(cin,line);
	}
}
