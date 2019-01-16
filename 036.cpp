#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		unordered_map<char,int> box;
		for(auto row : board){
			for(auto cell : row)
				if(cell!='.'){
					if(box[cell]>0)
						return false;
					++box[cell];
				}
			box.clear();
		}
		for(int col=0; col<9; ++col){
			for(int row=0; row<9; ++row){
				char cell = board[row][col];
				if(cell!='.'){
					if(box[cell]>0)
						return false;
					++box[cell];
				}
			}
			box.clear();
		}
		for(int col=0; col<9; ++col){
			int r = col/3*3, c = col%3*3;
			for(int row=0; row<9; ++row){
				int r1 = row/3, c1 = row%3;
				char cell = board[r+r1][c+c1];
				if(cell!='.'){
					if(box[cell]>0)
						return false;
					++box[cell];
				}
			}
			box.clear();
		}
		return true;
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

