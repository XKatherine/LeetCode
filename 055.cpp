#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		if(nums.size() == 0) return false;
		if(nums.size() == 1) return true;

		int des = nums.size() - 1;

		int i = 0;
		int pos = 0;
		int max_reach = 0;
		while (pos <= max_reach) {
			for(int i = 0; i < nums[pos]; i++){
				max_reach = max(max_reach, pos + nums[pos+i]);
				if(max_reach >= des) return true;
			}
			++pos;
		}
		return false;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ']', ' ');

		istringstream is(line);
		int n;
		vector<int> v;
		while(is>>n) v.push_back(n);

		cout<<s.canJump(v)<<endl;
	}
}
