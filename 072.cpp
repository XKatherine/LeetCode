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

		//Sign : last operation is "D", "I", "M", "R"
		vector<char> op;
		while(ind1 >=  0 && ind2 >= 0){
			if(word1[ind1] != word2[ind2]){
				if(d[ind1+1][ind2] > d[ind1][ind2+1]){
					if(op.size() > 0 && op.back() == 'D'){
						op.pop_back();
						op.push_back('M');
					}else op.push_back('I');
					--ind2;
				}else if(d[ind1+1][ind2] < d[ind1][ind2+1]){
					if(op.size() > 0 && op.back() == 'I'){
						op.pop_back();
						op.push_back('M');
					}else op.push_back('D');
					--ind1;
				}else{
					if(ind1 > ind2){
						--ind1;
						op.push_back('D');
					}else{
						--ind2;
						op.push_back('I');
					}
				}
			}else{
				--ind1;
				--ind2;
				op.push_back('R');
			}
		}

		while(ind1-- >= 0) op.push_back('D');
		while(ind2-- >= 0) op.push_back('I');
		for(auto i : op)
			cout<<i<<" ";
		cout<<endl;

		int ret = 0;
		int dd = 0;
		int ii = 0;
		int rr = 0;
		while(i >= 0){
			char c = op[i];
			if(c == 'D') ++dd;
			else if(c == 'I') ++ii;
			else if(c == 'R' && ((!dd && !ii)||(op.))) ++rr;
		}


		return 8;
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
