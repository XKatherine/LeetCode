#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
		if(x == 0) return 0;
		int ret = 1;
		while((ret<<1)<=x/(ret<<1)) ret<<=1;
		while((ret+1)<=x/(ret+1)) ++ret;
		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		istringstream is(line);
		int n;

		is >> n;
		cout<<s.mySqrt(n)<<endl;
	}
}

