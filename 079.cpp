#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    bool exist_(int i, int j, vector<vector<char>>& board, string word) {
		if(word.length() == 0) return true;

		int m = board.size();
		int n = board[0].size();
		if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[0] || board[i][j] == '0') return false;

		board[i][j] = '0';
		if(exist_(i+1, j, board, word.substr(1)))
			return true;
		if(exist_(i-1, j, board, word.substr(1)))
			return true;
		if(exist_(i, j+1, board, word.substr(1)))
			return true;
		if(exist_(i, j-1, board, word.substr(1)))
			return true;
		board[i][j] = word[0];

		return false;
	}
    bool exist(vector<vector<char>>& board, string word) {
		if(board.size() == 0) return false;
		if(word.length() == 0) return false;

		for(int i = 0; i < board.size(); ++i)
			for(int j = 0; j < board[0].size(); ++j)
				if(board[i][j] == word[0]){
					board[i][j] = '0';
					if(exist_(i-1, j, board, word.substr(1)))
						return true;
					if(exist_(i+1, j, board, word.substr(1)))
						return true;
					if(exist_(i, j+1, board, word.substr(1)))
						return true;
					if(exist_(i, j-1, board, word.substr(1)))
						return true;
					board[i][j] = word[0];
				}
		return false;
    }
};

int main(){
	Solution s;
	string line;
	vector<vector<char>> b;
	getline(cin, line);
	getline(cin, line);
	while(line != "]"){
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), '\'', ' ');

		istringstream is(line);
		vector<char> v;
		char c;

		while( is >> c ) v.push_back(c);
		b.push_back(v);
		getline(cin, line);
	}

	getline(cin,line);
	cout<<s.exist(b, line)<<endl;
}
