#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if(strs.size()==0)
			return "";
		string ans = "";

		//loop on ans
		for(int i=0; i<strs[0].length(); i++){
			char c = strs[0][i];
			bool isSame = true;
			//loop on every string
			for(int j=1; j<strs.size(); j++){
				if(strs[j][i]!=c){
					isSame = false;
					break;
				}	
			}
			if(!isSame)
				break;
			ans += c;
		}
		return ans;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		istringstream is(line);
		vector<string> v;
		string str;
		while(is>>str){
			v.push_back(str);
		}
		cout<<s.longestCommonPrefix(v)<<endl;
	}
}
