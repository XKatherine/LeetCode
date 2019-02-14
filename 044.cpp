#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		//ending point
		if(s == p) return true;
		if(p == "") return false;
		if(s == ""){
			for(auto i : p)
				if(i != '*')
					return false;
			return true;
		}

		//Case I : p[0] == '?'
		if(p[0] == '?') return isMatch(s.substr(1), p.substr(1));

		//Case II : p[0] == '*'
		if(p[0] == '*'){
			//loop until p[move] != '*'
			int move = 1;
			while(move < p.length() && p[move] == '*') ++move;

			//Situation (a) : The end
			if(move == p.length()) return true;

			//Situation (b) : there is a '?' afterwards
			if(p[move] == '?') return isMatch(s.substr(1), "*" + p.substr(move+1));

			//Situation (c) : there is a char(a-z) afterwards
			//variable patLen : char pattern
			int patLen = 1;
			while(patLen + move < p.length() && p[patLen + move] != '?' && p[patLen + move] != '*') ++patLen;

			//FIRST OF ALL
			int next = s.find(p.substr(move, patLen));
			if(next == string::npos) return false;

			//Situation (c-1) : after the pattern is the end
			if(patLen + move == p.length())
				return s.substr(s.length() - patLen) == p.substr(move);
			//Situation (c-2) : after the pattern is the '*'
			if(p[patLen + move] == '*'){
				return isMatch(s.substr(next + patLen), p.substr(move + patLen));
			}
			//Situation (c-3)
			while(next != string::npos){
				if(isMatch(s.substr(next + patLen), p.substr(move + patLen)))
					return true;
				s = s.substr(next + 1);
				next = s.find(p.substr(move, patLen));
			}
			return false;
		}

		//Case III : p[0] is char(a-z)
		int patLen = 1;
		while(patLen < p.length() && p[patLen] != '?' && p[patLen] != '*') ++patLen;
		if(s.find(p.substr(0, patLen)) == 0)
			return isMatch(s.substr(patLen), p.substr(patLen));
		return false;
    }
};

int main(){
	Solution s;
	string line1;
	while(getline(cin, line1)){
		string line2;
		getline(cin, line2);

		line1 = line1.substr(1);
		line2 = line2.substr(1);
		int stop1 = line1.find('"');
		int stop2 = line2.find('"');
		line1 = line1.substr(0, stop1);
		line2 = line2.substr(0, stop2);

		cout<<s.isMatch(line1, line2)<<endl;
	}
}
