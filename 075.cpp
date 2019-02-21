#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		int r = nums.size()-1;
		int l = 0;
		for(; l < r; l++){
			if(nums[l] != 0){
				int temp = nums[l];
				nums[l--] = nums[r];
				nums[r--] = temp;
			}
		}
		l = nums[l]==0 ? l+1 : l;
		r = nums.size()-1;
		for(; l < r; r--){
			if(nums[r] != 2){
				int temp = nums[l];
				nums[l++] = nums[r];
				nums[r++] = temp;
			}
		}
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ',', ' ');

		istringstream is(line);
		vector<int> v;
		int n;
		while(is >> n) v.push_back(n);

		s.sortColors(v);

		for(auto i : v) cout<<i<<" ";
		cout<<endl;
	}
}
