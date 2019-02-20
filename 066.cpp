#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		int pos = digits.size()-1;

		while(pos >= 0 && carry > 0){
			int temp = digits[pos];
			digits[pos] = (temp+carry)%10;
			carry = (temp+carry)/10;
			--pos;
		}

		if(pos < 0 && carry > 0) digits.insert(digits.begin(), carry);

		return digits;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ']', ' ');
		int n;
		vector<int> v;
		istringstream is(line);
		while(is >> n) v.push_back(n);

		vector<int> ans = s.plusOne(v);
		for(auto i : ans) cout << i << " ";
		cout<<endl;
	}
}
