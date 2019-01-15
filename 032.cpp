#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<stack>
#include<algorithm>

class Solution {
public:
	int findLen(std::vector<int> v){
		std::sort(v.begin(),v.end());
		int size = v.size();
		int ret = 1, cnt = 1;
		if(size<2) return size;
		for(int i=0;i<size-1;i++){
			if(v[i]==v[i+1]-1)
				++cnt;
			else{
				ret = std::max(ret,cnt);
				cnt = 1;
			}
		}
		ret = std::max(ret,cnt);
		return ret;
	}

    int longestValidParentheses(std::string s) {
		int len = s.length();
		if(len<2) return 0;

		std::stack<int> st;
		//std::unordered_map<int,int> nums;
		std::vector<int> v;
		int maxi=0, left=0;
		for(int i=0; i<len; i++){
			if(s[i]=='('){
				st.push(left++);
			}else{
				if(st.empty()){
					int size = findLen(v);
					maxi = std::max(maxi,size);
					left = 0;
					v.clear();
				}else{
					v.push_back(st.top());
					st.pop();
				}			
			}
		}
		maxi = std::max(maxi,findLen(v));
		return maxi*2;
    }
};

int main(){
	Solution s;
	std::string line;
	while(std::getline(std::cin,line)){
		std::cout<<s.longestValidParentheses(line)<<std::endl;
	}
}
