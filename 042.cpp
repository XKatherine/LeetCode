#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		int ret = 0;
		int len = height.size();
		if(len <= 1) return ret;

		auto it1 = max_element(height.begin(), height.end());
		int max = *it1;
		*it1 = -1;
		auto it2 = max_element(height.begin(), height.end());
		int sub_max = *it2;
		
		while(sub_max > 0){
			auto left = it1 < it2 ? it1 : it2;
			auto right = left == it1 ? it2 : it1;
			int lvalue = left == it1 ? max : sub_max;
			int rvalue = left == it1 ? sub_max : max;

			for(auto i = left + 1; i < right; ++i){
				if(*i < 0){
					ret += (i-left-1)*(lvalue - sub_max);
					do{ i++; }while(*i < 0 && i < right);
					for(auto j = i; j < right; ++j){
						ret += rvalue - *j;	
						*j = -1;
					}
				//	it1 = it2;
				//	max = sub_max;
				//	*it1 = -1;
				//	it2 = max_element(height.begin(), height.end());
				//	sub_max = *it2;
				//	cout<<"sub_max" << sub_max<<endl;
					break;
				}else{
					ret += sub_max - *i;	
					*i = -1;
				}
			}
            
			cout<< "ret:"<< ret << endl;
            
			it1 = it2;
			max = sub_max;
			*it1 = -1;
			it2 = max_element(height.begin(), height.end());
			sub_max = *it2;
		}

		return ret;
	}
	/* Memory Limit Exceed
    int trap(vector<int>& height) {
		int len = height.size();
		if(len <= 1) return 0;
		auto it = max_element(begin(height), end(height));
		vector<vector<int>> hvec(*it);

		for(int i = 0; i < len; i++){
			int h = height[i];
			if(h > 0)
				for(int j = 0; j < h; ++j)
					hvec[j].push_back(i); 
		}

		int ret = 0;
		for(auto i : hvec){
			int size = i.size();
			if(size > 1)
				for(int j = 0; j < size - 1; ++j)
					ret += i[j+1] - i[j] - 1;
		}

		return ret;
    }
	*/
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), ',', ' ');
		int n;
		vector<int> v;
		istringstream is(line);
		while(is >> n)
			v.push_back(n);

		cout<<s.trap(v)<<endl;
	}
}
