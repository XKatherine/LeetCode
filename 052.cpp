#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	void helper(int cur, int col, int d1, int d2, int n, int& ret){
		if(cur == n){
			ret ++;
			return;
		}

		int mask = col | d1 | d2;

		for(int i = 0, b = 1; i < n; ++i, b <<= 1)
			if(!(mask & b))
				helper(cur+1, col|b, (d1|b)<<1, (d2|b)>>1, n, ret);
	}

    int totalNQueens(int n){ 
		int ans = 0;

		helper(0, 0, 0, 0, n, ans); 

		return ans;
    }
};

int main(){
	Solution s;
	int n;
	while(cin >> n){
		cout<<s.totalNQueens(n)<<endl;
	}
}
