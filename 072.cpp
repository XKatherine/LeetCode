#include<iostream>
#include<stack>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
		int len1 = word2.length();
		int len2 = word1.length();
		int d[len1+1][len2+1];
		memset(d[0], 0, sizeof(int)*(len1+1)*(len2+1));

		for(int i = 0; i < len1; ++i)
			for(int j = 0; j < len2; ++j){
				if(word1[i] == word2[j])
					d[i+1][j+1] = d[i][j]+1;
				else
					d[i+1][j+1] = max(d[i][j+1], d[i+1][j]);
			}

		int ind1 = len1-1;
		int ind2 = len2-1;

		int deletes = 0;
		int inserts = 0;
		int modifis = 0;

		while(ind1 > 0 && ind2 > 0){
			if(word2[ind1] != word1[ind2]){
				if(d[ind1+1][ind2] >= d[ind1][ind2+1]){
					deletes++;
					--ind2;
				}else{
					inserts++;
					--ind1;
				}
			}else{
				--ind1;
				--ind2;
			}
		}

		if(word2[ind1] == word1[ind2]) inserts += ind2 + ind1;
		else if(ind1 == ind2) modifis++;
		else inserts += ind2 + ind1;

		return deletes + inserts + modifis;
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
