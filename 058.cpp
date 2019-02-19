#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
		int start = s.length() - 1;
		while(start >= 0 && s[start]==' ')
			--start;
		if(start < 0) return 0;

		int cnt = 0;
		while(start >= 0 && s[start]!=' '){
			cnt ++;
			--start;
		}
		return cnt;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		cout<<s.lengthOfLastWord(line)<<endl;
	}
}
