#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int start = 0, sto = nums[0], cur = 0;
		
		for(int i = 1; i < nums.size(); i++){
			if(nums[start] < 0 && nums[i] > nums[start]){
				start = i;
				sto = nums[start];
			}else if(nums[i] < 0){
				cur += nums[i];
				if(cur + sto < 0){
					start = i;
					sto = nums[i];
					cur = 0;
				}if(cur > 0){
					sto += cur;
					cur = 0;
				}
			}else{
				sto += nums[i];
			}
		}

		return sto;

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

		while(is >> n) v.push_back(n);

		cout << s.maxSubArray(v) << endl;
	}
}
