#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		if(num1 == "0" || num2 == "0") return "0";
		int len1 = num1.length();
		int len2 = num2.length();
		string ret = "";

		for(int i = len2 - 1; i >= 0; --i){
			int m2 = num2[i] - '0';
			int carry = 0;
			string part = "";

			for(int j = len1 - 1; j >= 0; --j){
				int m1 = num1[j] - '0';
				string ans = to_string((m1*m2+carry)%10);
				carry = (m1*m2 + carry)/10;
				part = ans + part;
			}

			if(carry) part = to_string(carry) + part;

			string offset(len2 - 1 - i, '0');
			part += offset;

			carry = 0;
			string newRet = "";

			int cnt = 1;
			while(cnt <= ret.length()){
				int n1 = part[part.length() - cnt] - '0';
				int n2 = ret[ret.length() - cnt] - '0';
				string ans = to_string((n1+n2+carry)%10);
				carry = (n1 + n2 + carry)/10;
				newRet = ans + newRet;
				cnt++;
			}

			if(part.length() - cnt >= 0)
				while(cnt <= part.length()){
					int n1 = part[part.length() - cnt] - '0';
					string newAdd = to_string((carry + n1)%10);
					carry = (carry + n1)/10;
					newRet = newAdd + newRet;
					cnt++;
				}

			if(carry) newRet = to_string(carry) + newRet;

			ret = newRet;
		}

		return ret;
    }
};

int main(){
	Solution s;
	string num1;
	while(getline(cin, num1)){
		string num2;
		getline(cin, num2);

		cout<<s.multiply(num1, num2)<<endl;
	}
}
