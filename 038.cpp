#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		int n;
		istringstream is(line);
		is>>n;
		cout<<coutAndSay(n)<<endl;
	}
}
