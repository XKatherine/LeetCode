#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		int size = heights.size();
		if(size == 0) return 0;
		if(size == 1) return heights[0];

		int ret = heights[0];
		for(int i = 0; i < size; ++i){
			int last = heights[i];
			ret = max(last, ret);
			for(int j = i+1; j < size; ++j){
				last = min(last, heights[j]);
				ret = max(last*(j-i+1), ret);
			}
		}

		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), '[', ' ');

		stringstream is(line);
		vector<int> v;
		int n;
		while(is >> n) v.push_back(n);

		cout<<s.largestRectangleArea(v)<<endl;
	}
}
