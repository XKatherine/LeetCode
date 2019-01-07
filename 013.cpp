#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		int start = 0;
		int len = s.length();
		int ans = 0;
		while(start<len){
			switch(s[start]){
				case 'I':
					if(s[start+1]=='V'){
						ans += 4;
						start += 2;
					}else if(s[start+1]=='X'){
						ans += 9;
						start += 2;
					}else{
						ans += 1;
						start += 1; 
					}
					break;
				case 'V':
					ans += 5;
					start += 1;
					break;
				case 'X':
					if(s[start+1]=='L'){
						ans += 40;
						start += 2;
					}else if(s[start+1]=='C'){
						ans += 90;
						start += 2;
					}else{
						ans += 10;
						start += 1; 
					}
					break;
				case 'L':
					ans += 50;
					start += 1;
					break;
				case 'C':
					if(s[start+1]=='D'){
						ans += 400;
						start += 2;
					}else if(s[start+1]=='M'){
						ans += 900;
						start += 2;
					}else{
						ans += 100;
						start += 1; 
					}
					break;
				case 'D':
					ans += 500;
					start += 1;
					break;
				case 'M':
					ans += 1000;
					start += 1;
					break;
			}	
		}
		return ans;
    }
};

int main(){
	Solution s;
	string str;
	while(getline(cin,str)){
		cout<<s.romanToInt(str)<<endl;
	}
}
