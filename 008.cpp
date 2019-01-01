#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
		int start = 0;
		bool isPos = true;
		long n = 0;

		//delete the white spaces
		while(str[start]==' ') start++;

		//detect the sign of the number
		if(str[start]=='-'){
			isPos = false;
			start++;
		}else if(str[start]=='+'){
			start++;
		}

		//justify if the number is valid
		if(str[start]<'0' || str[start]>'9')
			return 0;

		//ending point of the number (not included)
		int end = start;
		while(str[end]>='0' && str[end]<='9') end++;
		if(isPos){
			for(int i=start;i<end;i++){
				n *= 10;
				n += str[i]-'0';
				//justify if n is out of range
				if(n>INT_MAX)
					return INT_MAX;
			}
			return (int)n;
		}else{
			for(int i=start;i<end;i++){
				n *= 10;
				n += str[i]-'0';
				//justify if n is out of range
				if(n*(-1)<INT_MIN)
					return INT_MIN;
			}
			return (int)n*(-1);

		}
    }
};

int main(){
	Solution s;
	string a;
	while(getline(cin,a)){
		cout<<s.myAtoi(a)<<endl;
	}
}
