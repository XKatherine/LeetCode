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

		if(len1 > len2){
			int reserve = lcs(word
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
