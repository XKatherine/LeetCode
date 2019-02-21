#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if(n < 3) return n;
		int save = 1;
		int move = 0;
		for(int i = 1; i < n; i++){
			if(nums[i] == nums[i-1])
				save++;
			else{
				if(save > 2) move += save - 2;
				save = 1;
			}
			nums[i-move] = nums[i];
		}

		if(save > 2) move += save - 2;

		return n - move;
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

		int x = s.removeDuplicates(v);
		for(int i = 0; i < x; i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
}
