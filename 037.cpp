#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	void solution1(vector<vector<char>>& board){
		bool isChanged = false;
		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++){
				unordered_map<char> can;
				if(board[i][j]!='.')

					break;
				for(auto c : board[i])
					if(c!='c')


    void solveSudoku(vector<vector<char>>& board) {
    }
};

int main(){
	Solution s;
	string line;
	vector<vector<char>> board;
	while(getline(cin,line)&&line!="]"){
		if(line=="[")
			continue;

		vector<char> v;
		char c;
		istringstream is(line);
		while(is>>c)
			if(c!=']'&&c!='['&&c!='"'&&c!=',')
				v.push_back(c);

		board.push_back(v);
	}
	cout<<s.isValidSudoku(board)<<endl;
}

