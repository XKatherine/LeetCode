#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, int> h;
		vector<vector<string>> ret;
		for(int i = 0; i < strs.size(); ++i){
			string item = strs[i];
			sort(item.begin(), item.end());

			auto it = h.find(item);
			if(it == h.end()){
				h[item] = ret.size(); 
				ret.push_back(vector<string>{strs[i]});
			}else
				ret[it->second].push_back(strs[i]);
		}

		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line, ']')){
		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), '[', ' ');

		string str;
		vector<string> v;
		istringstream is(line);
		while(is >> str) v.push_back(str);

		vector<vector<string>> ans = s.groupAnagrams(v);

		for(auto i : ans){
			for(auto j : i)
				cout << j <<" ";
			cout << endl;
		}
	}
}
