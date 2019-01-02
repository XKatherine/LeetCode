#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

		//Handle special cases
		if(x<0) return false;		

		//Handle normal cases
		else if(x>0){
			//reverse is the number after reversing
			int reverse = 0;
			int rest = x;
			do{
				reverse *= 10;
				reverse += rest%10;
				rest /= 10;
			}while(rest>0);
			return reverse == x;
		}else{
		//Case for 0
			return true;
		}
    }
};

int main(){
	Solution s;
	while(cin){
		int n;
		cin>>n;
		cout<<s.isPalindrome(n)<<endl;
	}
}

