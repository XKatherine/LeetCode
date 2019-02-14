#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
		int len = nums.size();
		vector<int> d(len, INT_MAX);
		d[len-1] = 0;

		for(int i = len - 2; i >= 0; --i)
			for(int j = 1; j <= nums[i] && i + j < len; ++j)
				if(d[i + j] < INT_MAX)
					d[i] = d[i] > 1 + d[i + j] ? 1 + d[i + j] : d[i];
		return d[0];
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line, ']')){
		line = line.substr(1);
		replace(line.begin(), line.end(), ',', ' '); 
		istringstream is(line);

		int n;
		vector<int> v;
		while(is >> n) v.push_back(n);

		cout << s.jump(v) << endl;
	}
}
