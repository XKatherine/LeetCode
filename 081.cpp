#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), ',', ' ');

		istringstream is(line);
		vector<int> v;
		int n;
		while(is>>n) v.push_back(n);

		getline(cin, line);
		int target = stoi(line);

		cout<<s.search(v, target);
	}
}
