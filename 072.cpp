#include<iostream>
#include<stack>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
	int score(string s){
		int deletes = 0;
		int inserts = 0;
		int modifies = 0;
		stack<char> stk;

		for(int i = 0; i < s.length(); i++){
			if(s[i] == '0'){
				if(stk.empty() || stk.top() == '0'){
					deletes++;
					stk.push('0');
				}else{
					inserts--;
					modifies++;
					stk.pop();
				}
			}else if(s[i] == '2'){
				if(stk.empty() || stk.top() == '2'){
					inserts++;
					stk.push('2');
				}else{
					deletes--;
					modifies++;
					stk.pop();
				}
			}else{
				while(!stk.empty())
					stk.pop();
			}
		}

		return deletes + inserts + modifies;
	}

	void findSCS(vector<vector<int>>& d, string word1, string word2, int i1, int i2, int i, vector<string>& ret, string s){
		int len1 = word1.length();
		int len2 = word2.length();
		int len = d[len1][len2] - i;

		if(i == d[len1][len2]) ret.push_back(s);

		while(i1 >= 0 && i2 >= 0 && len > 0){
			if(word1[i1] == word2[i2]){
				s[--len] = '1';
				--i1;
				--i2;
			}else if(d[i1][i2+1] < d[i1+1][i2]){
				s[--len] = '0';
				--i1;
			}else if(d[i1][i2+1] > d[i1+1][i2]){
				s[--len] = '2';
				--i2;
			}else{
				++i;
				s[--len] = '0';
				findSCS(d, word1, word2, i1-1, i2, i, ret, s);
				s[len] = '2';
				findSCS(d, word1, word2, i1-1, i2, i, ret, s);
				return;
			}
			++i;
		}
		while(i1 >= 0){
			s[--len] = '0';
			--i1;
			++i;
		}
		while(i2 >= 0){
			s[--len] = '2';
			--i2;
			++i;
		}

		if(i == d[len1][len2]) ret.push_back(s);
	}

    int minDistance(string word1, string word2) {
		int len1 = word1.length();
		int len2 = word2.length();
		vector<vector<int>> d(len1+1, vector<int>(len2+1));

		for(int i = 1; i <= len1; i++) d[i][0] = i;
		for(int i = 0; i <= len2; i++) d[0][i] = i;

		for(int i = 1; i <= len1; i++)
			for(int j = 1; j <= len2; j++){
				if(word1[i-1] == word2[j-1])
					d[i][j] = d[i-1][j-1] + 1;
				else 
					d[i][j] = min(d[i][j-1], d[i-1][j]) + 1;
			}

		vector<string> v;
		string s(d[len1][len2], ' ');
		findSCS(d, word1, word2, len1-1, len2-1, 0, v, s);

		int mini = INT_MAX;
		for(auto i : v){
			int scor = score(i);
			if(scor < mini)
				mini = scor;
		}
		/*
		int len = d[len1][len2];
		int i1 = len1-1;
		int i2 = len2-1;
		string s1(len, ' ');
		string s2(len, ' ');
		while(i1 >= 0 && i2 >= 0 && len > 0){
			if(word1[i1] == word2[i2]){
				s1[--len] = '1';
				--i1;
				--i2;
			}else if(d[i1][i2+1] <= d[i1+1][i2]){
				s1[--len] = '0';
				--i1;
			}else{
				s1[--len] = '2';
				--i2;
			}
		}
		while(i1 >= 0){
			s1[--len] = '0';
			--i1;
		}
		while(i2 >= 0){
			s1[--len] = '2';
			--i2;
		}
		cout<<"s1: :"<<s1<<endl;

		len = d[len1][len2];
		i1 = len1-1;
		i2 = len2-1;
		while(i1 >= 0 && i2 >= 0 && len > 0){
			if(word1[i1] == word2[i2]){
				s2[--len] = '1';
				--i1;
				--i2;
			}else if(d[i1][i2+1] < d[i1+1][i2]){
				s2[--len] = '0';
				--i1;
			}else{
				s2[--len] = '2';
				--i2;
			}
		}
		while(i1 >= 0){
			s2[--len] = '0';
			--i1;
		}
		while(i2 >= 0){
			s2[--len] = '2';
			--i2;
		}
		*/


		return mini;
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
