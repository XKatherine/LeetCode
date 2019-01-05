#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {

		string ans;

		//Deal with 1000+
		while(num/1000>0){
			ans += "M";
			num -=1000;
		}

		//Rest X00
		while(num/100>0){
			if(num/100==9){
				ans += "CM";
				num -= 900;
			}else if(num/100<9 && num/100>4){
				ans += "D";
				num -= 500;
			}else if(num/100 == 4){
				ans += "CD";
				num -= 400;
			}else{
				ans += "C";
				num -= 100;
			}
		}

		//Rest X0
		while(num/10>0){
			if(num/10==9){
				ans += "XC";
				num -= 90;
			}else if(num/10<9 && num/10>4){
				ans += "L";
				num -= 50;
			}else if(num/10 == 4){
				ans += "XL";
				num -= 40;
			}else{
				ans += "X";
				num -= 10;
			}
		}
		
		//Rest X
		while(num>0){
			if(num==9){
				ans += "IX";
				num -= 9;
			}else if(num<9 && num>4){
				ans += "V";
				num -= 5;
			}else if(num == 4){
				ans += "IV";
				num -= 4;
			}else{
				ans += "I";
				num -= 1;
			}
		}
		return ans;
    }
};

int main(){
	Solution s;
	while(cin){
		int n;
		cin>>n;
		cout<<s.intToRoman(n)<<endl;
	}
}
