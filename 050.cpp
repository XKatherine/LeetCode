#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
		if(n == 0) return 1;
		if(n == 1) return x;
		if(n == -1) return 1/x;

		double half = myPow(x, n/2);
		return half * half * myPow(x, n-2*(n/2));
    }
};

int main(){
	Solution s;
	int x;
	while(cin >> x){
		int n;
		cin >> n;

		cout << s.myPow(x, n) << endl;
	}
}
