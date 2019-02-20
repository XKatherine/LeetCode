#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		int len1 = a.length();
		int len2 = b.length();
		string ret = "";

		int i = 1;
		int carry = 0;
		while( i <= len1 && i <= len2){
			int sum = (a[len1-i] - '0') + (b[len2-i] - '0') + carry;
			ret = to_string(sum%2) + ret;
			carry = sum/2;
			++i;
		}

		while(i <= len1){
			int sum = a[len1-i] - '0' + carry;
			ret = to_string(sum%2) + ret;
			carry = sum/2;
			++i;
		}

		while(i <= len2){
			int sum = b[len2-i] - '0' + carry;
			ret = to_string(sum%2) + ret;
			carry = sum/2;
			++i;
		}

		if(carry) ret = to_string(carry) + ret;
			
		return ret;
    }
};

int main(){
	Solution s;
	string s1;
	while(getline(cin, s1)){
		string s2;
		getline(cin, s2);

		cout<<s.addBinary(s1, s2)<<endl;
	}
}
