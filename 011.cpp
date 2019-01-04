#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int max = 0;
		for(int i=1; i<height.size(); i++)
			for(int j=0; j<height.size()-i; j++){
				int xmin = min(height[j], height[j+i]);
				int res = xmin*i;
				if(res>max)
					max = res;
			}
		return max;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		istringstream is(line);
		vector<int> v;
		int n;
		while(is>>n){
			v.push_back(n);
		}
		cout<<s.maxArea(v)<<endl;
	}	
}
