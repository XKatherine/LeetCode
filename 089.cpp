#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
		vector<int> ret{0};
		if(n ==0) return ret;
		int cnt = 1;
		for(int i = 0; i < n; ++i){
			int size = ret.size();
			for(int j = size-1; j >= 0; --j)
				ret.push_back(cnt + ret[j]);
			cnt <<= 1;
		}
		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		vector<int> v = s.grayCode(stoi(line));
		for(auto i : v)
			cout<< i << " ";
		cout<<endl;
	}
}
