#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
		int len = s.length();
		if(len == 0 || s[0] == '0') return 0;

		int d[len];
		d[len-1] = 1;
		if(s[len-1] == '0') d[len-1] = 0;
		if(len > 1){
			int tmp = stoi(s.substr(len-2,2));
			if(tmp > 9 && tmp < 27) d[len-2] = d[len-1] + 1; 
			else if(tmp > 9)
				d[len-2] = d[len-1];
			else
				d[len-2] = 0;
		}
		for(int i = len-3; i >= 0; --i){
			if(s[i] == '0')
				d[i] = 0;
			else{
				int tmp = stoi(s.substr(i,2));
				if(tmp > 9 && tmp < 27)
					d[i] = d[i+1] + d[i+2]; 
				else 
					d[i] = d[i+1];
			}
		}
		return d[0];
	}
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		cout<<s.numDecodings(line)<<endl;
	}
}
