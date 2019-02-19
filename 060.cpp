#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
		vector<int> fac(n);
		string s(n,'1');

		fac[0] = 1;
		for (int i = 1; i < n; ++i)
			fac[i] = fac[i-1]*i;

		int last = 0;
		vector<char> basket(n);
		for(int i = 0; i < n; ++i) basket[i] = '1'+i;

		k --;
		for (int i = 0; i < n; ++i){
			int c = (k/fac[n-i-1])%basket.size();
			s[i] = basket[c];
			basket.erase(basket.begin() + c);
			k -= k / fac[n-i-1]* fac[n-i-1];
		}

		return s;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		int n, k;
		istringstream is(line);

		is>>n>>k;

		cout<<s.getPermutation(n,k)<<endl;
	}
}
