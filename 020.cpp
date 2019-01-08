#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		if(s=="") return true;
		map<char,short> m{
			{'(', -3},
			{'[', -2},
			{'{', -1},
			{')', 3},
			{']', 2},
			{'}', 1},
		};
		stack<char> sk;
		for(int i=0; i<s.length(); i++){
			if(!sk.empty()){
				if(m[s[i]]<0){
					sk.push(s[i]);	
				}else{
					if(m[sk.top()]+m[s[i]]==0)
						sk.pop();
					else
						return false;
				}
			}else{
				if(m[s[i]]>0) return false;
				sk.push(s[i]);
			}
		}
		return sk.empty();
    }
};

int main(){
	Solution s;
	string str;
	while(getline(cin, str))
		cout<<s.isValid(str)<<endl;
}
