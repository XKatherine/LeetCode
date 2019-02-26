#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
		if(s1 == s2) return true;
		if(s1.length() != s2.length()) return false;
		if(s1.length() == 1) return s1 == s2;

		string cpy1 = s1;
		sort(cpy1.begin(), cpy1.end());
		string cpy2 = s2;
		sort(cpy2.begin(), cpy2.end());
		if(cpy1!=cpy2) return false;
		int len = s1.length();
		for(int i = 1; i<len; ++i)
			if(isScramble(s1.substr(0, i), s2.substr(len-i, i)) && isScramble(s1.substr(i, len-i), s2.substr(0, len-i)))
				return true;
		for(int i = 1; i<len; ++i)
			if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, len-i), s2.substr(i, len-i)))
				return true;
		return false;
    }
};

int main(){
	Solution s;
	string line1;
	while(getline(cin, line1)){
		string line2;
		getline(cin, line2);

		cout<<s.isScramble(line1,line2)<<endl;
	}
}
