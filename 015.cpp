#include<iostream>
#include<set>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	/*

	   Time Exceed

    vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > ans;
		set<vector<int> > s;
		// Special cases
		int size = nums.size();
		if(size<3)
			return ans;
        
		for(int i=0; i<size-2; i++){
			for(int j=i+1; j<size-1; j++){
				for(int k=j+1; k<size; k++){
					if(nums[i]+nums[j]+nums[k]==0){
						vector<int> v;
						v.push_back(nums[i]);
						v.push_back(nums[j]);
						v.push_back(nums[k]);
						sort(v.begin(),v.end());
						s.insert(v);
					}
				}
			}
		}
		set<vector<int> >::iterator it;
		for(it = s.begin(); it != s.end(); ++it ) {
        	ans.push_back( *it );
		}
		return ans;
    }
	*/
    vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > ans;
		set<vector<int> > s;
		unordered_map<int, vector<int> > map;
		int size = nums.size();
		if(size<3)
			return ans;

		sort(nums.begin(),nums.end());
		for(int i=0; i<size; i++){
			map[nums[i]].push_back(i);
		}	
		if(map.size()==1){
			if(map[0].size()>0){
				vector<int> v;
				v.push_back(0);
				v.push_back(0);
				v.push_back(0);
				ans.push_back(v);
				return ans;
			}else{
				return ans;
			}
		}

		for(int i=0; i<size-1; i++){
			if(i>0&&nums[i]==nums[i-1])
				continue;
			for(int j=i+1; j<size; j++){
				if(j>i+1&&nums[j]==nums[j-1])
					continue;
				int n = -nums[i]-nums[j];
				if(map[n].size()>0){
					bool isDiff = false;
					for(int k=0; k<map[n].size();k++)
						if(map[n][k]!=i && map[n][k]!=j){
							isDiff = true;
							break;
						}
					if(isDiff){
						vector<int> v;
						v.push_back(nums[i]);
						v.push_back(nums[j]);
						v.push_back(n);
						sort(v.begin(),v.end());
						s.insert(v);
					}
				}
			}
		}
		set<vector<int> >::iterator it;
		for(it = s.begin(); it != s.end(); ++it ) {
        	ans.push_back( *it );
		}
		return ans;
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
			if (is.peek() == ',')
            	is.ignore();
		}
		for(int i=0;i<s.threeSum(v).size();i++)
			cout<<s.threeSum(v)[i][0]<<" "<<s.threeSum(v)[i][1]<<" "<<s.threeSum(v)[i][2]<<endl;
	}
}
