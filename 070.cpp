#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		if(n == 0 || n == 1) return 1;

		int d[n+1];
		d[0] = 1;
		d[1] = 1;

		for(int i = 2; i <= n; i++)
			d[i] = d[i-1] + d[i-2];
		return d[n];
    }
};

int main(){
	Solution s;
	int n;
	while(cin>>n){
		cout<<": "<<s.climbStairs(n)<<endl;
	}
}
