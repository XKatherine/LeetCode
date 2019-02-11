#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
	string countAndSay(int n){
		return countAndSay("1", 1, n);
	}
    string countAndSay(string s, int cnt, int n) {
		if(cnt == n) return s;
		string ret = "";
		int l = 0;
		while(l < s.length()){
			int r = l + 1;
			while(r < s.length() && s[l]==s[r]) r++; 
			ret = ret + to_string(r-l) + s[l];
			l = r;
		}
		return countAndSay(ret, ++cnt, n);
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		int n;
		istringstream is(line);
		is>>n;
		cout<<s.countAndSay(n)<<endl;
	}
}
