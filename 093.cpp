#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	void ipAddress(int cnt, string s, string cur, vector<string>& ret){
		if(s.length() == 0) {
			if(cnt == 4 /*&& find(ret.begin(), ret.end(), cur) == ret.end()*/) ret.push_back(cur);
			return;
		}
		if(cnt == 4) return;
		if(cnt) cur += ".";

		if(s[0] == '0'){
			ipAddress(cnt+1, s.substr(1), cur+"0", ret);
			return;
		}
			
		for(int i = 1; i <= s.length() && i <= 3; ++i){
			if(stoi(s.substr(0,i)) < 256)
				ipAddress(cnt+1, s.substr(i), cur+s.substr(0,i), ret);
		}
	}

    vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		string cur;
		ipAddress(0, s, cur, ret);

		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		vector<string> ans = s.restoreIpAddresses(line);

		for(auto i : ans)
			cout<<i<<endl;
	}
}
