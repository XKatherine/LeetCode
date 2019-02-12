#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
		vector<vector<int>> v;
		if(candidates.size() == 1){
			if(target%candidates[0] == 0)
				v.push_back(vector<int>(target/candidates[0], candidates[0]));
			return v;
		}

		int currnum = candidates.back();
		candidates.pop_back();

		if(target%currnum == 0)
			v.push_back(vector<int>(target/currnum, currnum));
		for(int cnt = 0; cnt*currnum < target; ++cnt){
			vector<vector<int>> v1 = combinationSum(candidates, target-cnt*currnum);
			if(v1.size() > 0)
				for(auto i : v1){
					for(int k = 0; k < cnt; ++k)
						i.push_back(currnum);
					v.push_back(i);
				}
		}
		return v;
    }
};

int main(){
  Solution s;
  string line;
  while(getline(cin,line)){
	  string str = "";
	  vector<int> v;
	  for(auto i : line)
		  str += i == ',' ? ' ' : i;
	  istringstream is(str);
	  int n;
	  while(is >> n)
		  v.push_back(n);

	  int target;
	  cin >> target;
	  
	  vector<vector<int>> ans = s.combinationSum(v, target); 
	  for(auto i : ans){
		  for(auto j : i)
			  cout << j << " ";
		  cout<<endl;
	  }
  }
}

    
