#include<iostream>
#include<stack>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
		int len1 = word1.length();
		int len2 = word2.length();
		int d[len1+1][len2+1];

		for(int i = 0; i <= len1; ++i) d[i][0] = i;
		for(int i = 1; i <= len2; ++i) d[0][i] = i;

		for(int i = 1; i <= len1; ++i)
			for(int j = 1; j <= len2; ++j){
				if(word1[i-1] == word2[j-1])
					d[i][j] = min(min(d[i-1][j],d[i][j-1]) + 1,d[i-1][j-1]);
				else
					d[i][j] = min(min(d[i-1][j],d[i][j-1]),d[i-1][j-1])+ 1;
			}

		return d[len1][len2];
	}
};

int main(){
	Solution s;
	string s1;
	while(getline(cin, s1)){
		string s2;
		getline(cin, s2);

		cout<<s.minDistance(s1, s2)<<endl;
	}
}
